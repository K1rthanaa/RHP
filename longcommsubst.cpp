#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    int maxLen = 0;
    int endIndex = 0;

    vector<vector<int>> substring(s1.length() + 1,
                                  vector<int>(s2.length() + 1, 0));

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                substring[i][j] = substring[i - 1][j - 1] + 1;

                if (substring[i][j] > maxLen) {
                    maxLen = substring[i][j];
                    endIndex = i;
                }
            }
        }
    }

    cout << "Length : " << maxLen << endl;
    cout << "And the substring is : ";

    for (int k = endIndex - maxLen; k < endIndex; k++) {
        cout << s1[k];
    }

    cout << endl;

    return 0;
}