#include <iostream>
using namespace std;
// Implements the Longest Common Subsequence (LCS) problem using dynamic programming
int main() {
    string A = "bd";
    string B = "abcd";

    int n = A.size();
    int m = B.size();

    int LCS[n + 1][m + 1]; 

 
    for (int i = 0; i <= n; ++i)
        LCS[i][0] = 0; 
    for (int j = 0; j <= m; ++j)
        LCS[0][j] = 0; 

  
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    cout << "Length of LCS: " << LCS[n][m] << endl;

    
    string result = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            result = A[i - 1] + result;
            --i;
            --j;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    cout << "LCS string: " << result << endl;

    return 0;
}