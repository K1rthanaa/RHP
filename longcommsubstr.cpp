#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    vector<vector<int>> lcs(s1.length() + 1,
                            vector<int>(s2.length() + 1, 0));

    // Build DP table
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[s1.length()][s2.length()] << endl;
    cout << "And the subsequence is : ";

    int i = s1.length();
    int j = s2.length();
    string ans = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (lcs[i - 1][j] >= lcs[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }

        cout << i << " " << j << endl;  // same as Java debug output
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
