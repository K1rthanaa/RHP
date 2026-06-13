#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter integers: ";
    for (int i = 0; i < n; i++)cin >> arr[i];

    int fm = arr[0];
    int sm = arr[1];

    for (int i = 1; i < n; i++) {
        if (arr[i] >= fm) {
            sm = fm;
            fm = arr[i];
        }
        else if (arr[i] > sm) {
            sm = arr[i];
        }
    }

    cout << "First maximum: " << fm << endl;
    cout << "Second maximum: " << sm << endl;
    
    return 0;
}