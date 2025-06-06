#include <iostream>
using namespace std;

int main() {
    // Profit (P) and weight (wt) arrays (1-based indexing used by adding dummy 0 at index 0)
    int P[5] = {0, 1, 2, 5, 6};     // Profits for items 1 to 4
    int wt[5] = {0, 2, 3, 4, 5};    // Weights for items 1 to 4

    int m = 8;                      // Maximum capacity of knapsack
    int n = 4;                      // Number of items

    int K[5][9];                    // DP table: K[i][w] stores max profit for i items and weight w

    // Build the DP table using bottom-up approach
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) { 
                // Base case: 0 items or 0 capacity => 0 profit
                K[i][w] = 0; 
            } else if (wt[i] <= w) {
                // If weight of current item i is less than or equal to current capacity w
                // Decide to include or exclude item i based on max profit
                K[i][w] = max(P[i] + K[i - 1][w - wt[i]], K[i - 1][w]);
            } else {
                // If current item's weight exceeds current capacity, can't include it
                K[i][w] = K[i - 1][w]; 
            }
        }
    }

    // Output the maximum value that can be placed in the knapsack
    cout << "Maximum value in knapsack = " << K[n][m] << endl;

    // Trace back the DP table to find which items are included in the optimal solution
    int w = m;
    cout << "Items included (1-based index): ";
    for (int i = n; i > 0 && w > 0; i--) {
        // If the value comes from including item i
        if (K[i][w] != K[i - 1][w]) {
            cout << i << " ";        // Print the index of the included item
            w = w - wt[i];           // Reduce the remaining capacity
        }
    }
    // If no items are included, this will not print anything
    cout << endl;

    return 0;
}