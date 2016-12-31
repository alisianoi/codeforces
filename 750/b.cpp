#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; int total = 0; int t; string dir;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t >> dir;

        if (total == 0 && dir[0] != 'S') {
            cout << "NO" << endl; return 0;
        } else if (total == 20000 && dir[0] != 'N') {
            cout << "NO" << endl; return 0;
        }

        if (dir[0] == 'E' || dir[0] == 'W') continue;

        if (dir[0] == 'S')
            total += t;
        else
            total -= t;

        if (total > 20000) {
            cout << "NO" << endl; return 0;
        } else if (total < 0) {
            cout << "NO" << endl; return 0;
        }
    }

    if (total == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
