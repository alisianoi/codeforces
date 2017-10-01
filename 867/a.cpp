#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n; string s; cin >> s;

    int ltr = 0, rtl = 0;
    for (int i = 1; i != n; ++i) {
        if (s[i - 1] == 'S' && s[i] != 'S') {
            ltr++;
        } else if (s[i - 1] != 'S' && s[i] == 'S') {
            rtl++;
        }
    }

    if (ltr > rtl) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
