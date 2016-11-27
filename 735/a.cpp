#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, k; cin >> n >> k;

    string s; cin >> s;

    int i = 0;
    for (; i < n; ++i) {
        if (s[i] == 'G' || s[i] == 'T') break;
    }

    int j = i + k;
    for (; j < n; j += k) {
        if (s[j] == '#') {
            cout << "NO" << endl; return 0;
        }

        if (s[j] == 'G' || s[j] == 'T') break;
    }

    if (j < n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
