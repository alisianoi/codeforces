#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;
    int l; cin >> l;

    auto xs = vector<int>(n, 0);
    auto ys = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> ys[i];
    }

    int x = l - xs[n - 1];
    int y = l - ys[n - 1];

    for (int i = n - 1; i > 0; --i) {
        xs[i] = xs[i] - xs[i - 1];
        ys[i] = ys[i] - ys[i - 1];
    }

    xs[0] += x;
    ys[0] += y;

    for (int i = 0; i < n; ++i) {
        if (xs == ys) {
            cout << "YES" << endl; return 0;
        }

        rotate(ys.begin(), next(ys.begin()), ys.end());
    }

    cout << "NO" << endl;
}
