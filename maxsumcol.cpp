#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> dp(rows);

    // Initialize with first column
    for (int i = 0; i < rows; i++) {
        dp[i] = matrix[i][0];
    }

    // Process remaining columns
    for (int col = 1; col < cols; col++) {
        vector<int> newDp(rows);

        for (int row = 0; row < rows; row++) {
            int best = INT_MIN;

            for (int prevRow = 0; prevRow < rows; prevRow++) {
                if (prevRow != row) {
                    best = max(best, dp[prevRow] + matrix[row][col]);
                }
            }

            newDp[row] = best;
        }

        dp = newDp;
    }

    int ans = INT_MIN;
    for (int val : dp) {
        ans = max(ans, val);
    }

    cout << ans << endl;

    return 0;
}