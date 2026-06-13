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

    vector<int> dp(cols);

    // Initialize with first row
    for (int j = 0; j < cols; j++) {
        dp[j] = matrix[0][j];
    }

    // Process remaining rows
    for (int row = 1; row < rows; row++) {
        vector<int> newDp(cols);

        for (int col = 0; col < cols; col++) {
            int best = INT_MIN;

            for (int prevCol = 0; prevCol < cols; prevCol++) {
                if (prevCol != col) {
                    best = max(best, dp[prevCol] + matrix[row][col]);
                }
            }

            newDp[col] = best;
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
