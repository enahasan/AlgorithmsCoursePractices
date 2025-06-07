#include <iostream>
using namespace std;

// Solves the Longest Common Subsequence (LCS) problem using Dynamic Programming
int main() {
    string A = "bd";   // First input string
    string B = "abcd"; // Second input string

    int n = A.size();  // Length of string A
    int m = B.size();  // Length of string B

    // Create a 2D array (n+1 x m+1) to store LCS lengths for substrings of A and B
    int LCS[n + 1][m + 1];

    // Initialize the first row and first column of the LCS table with 0
    // This handles the case where one of the strings is empty
    for (int i = 0; i <= n; ++i)
        LCS[i][0] = 0;

    for (int j = 0; j <= m; ++j)
        LCS[0][j] = 0;

    // Fill the LCS table using bottom-up dynamic programming
    for (int i = 1; i <= n; ++i) {       // Loop through each character in A
        for (int j = 1; j <= m; ++j) {   // Loop through each character in B
            if (A[i - 1] == B[j - 1]) {
                // If characters match, extend the previous LCS by 1
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
                // If characters don't match, take the longer LCS found so far
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    // Print the length of the longest common subsequence
    cout << "Length of LCS: " << LCS[n][m] << endl;

    // Recover the actual LCS string by tracing back from LCS[n][m]
    string result = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            // If current characters in A and B match, include in result
            result = A[i - 1] + result;
            --i;
            --j;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            // Move in the direction of the larger value (upward in table)
            --i;
        } else {
            // Move left in the table
            --j;
        }
    }

    // Print the actual longest common subsequence string
    cout << "LCS string: " << result << endl;

    return 0;
}