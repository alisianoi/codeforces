#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    auto xs = vector<int>(n, 0);

    for (int i = 0; i != n; ++i) {
        cin >> xs[i];
    }

    sort(xs.begin(), xs.end());

    for (int i = 0; i != n / 2; ++i) {
        if (xs[i] != xs[0]) {
            cout << "NO" << endl; return 0;
        }
    }

    for (int i = n / 2; i != n; ++i) {
        if (xs[i] != xs[n / 2]) {
            cout << "NO" << endl; return 0;
        }
    }

    if (xs[n / 2 - 1] != xs[n / 2]) {
        cout << "YES" << endl;
        cout << xs[n / 2 - 1] << " " << xs[n / 2] << endl;
    } else {
        cout << "NO" << endl;
    }
}
