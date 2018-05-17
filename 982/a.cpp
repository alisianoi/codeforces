#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n; cin >> n;

    string s; cin >> s;

    if (n == 1) {
        if (s[0] == '1') {
            cout << "Yes" << endl;

            return 0;
        } else {
            cout << "No" << endl;

            return 0;
        }
    } else if (n == 2) {
        if ((s[0] == '1' && s[1] == '0') || (s[0] == '0' && s[1] == '1')) {
            cout << "Yes" << endl;

            return 0;
        } else {
            cout << "No" << endl;

            return 0;
        }
    } else {

        if (s[0] == '0' && s[1] == '0') {
            cout << "No" << endl;

            return 0;
        }

        if (s[n - 1] == '0' && s[n - 2] == '0') {
            cout << "No" << endl;

            return 0;
        }
        
        for (size_t i = 0, j = 1, k = 2; k != n; ++i, ++j, ++k) {
            if (s[i] == '0' && s[j] == '0' && s[k] == '0') {
                cout << "No" << endl;

                return 0;
            } else if ((s[i] == '1' && s[j] == '1') || (s[j] == '1' && s[k] == '1')) {
                cout << "No" << endl;

                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
