#include<bits/stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui64 n; cin >> n;
    auto xs = vector<ui64>(n, 0);
    auto ys = vector<ui64>(n, 0);

    for (ui64 i = 0; i != n; ++i) {
        cin >> xs[i];
    }

    for (ui64 i = 0; i != n; ++i) {
        cin >> ys[i];
    }

    ui64 total = numeric_limits<ui64>::max();

    for (ui64 i = 1; i != n - 1; ++i) {

        ui64 ltotal = numeric_limits<ui64>::max();
        for (ui64 lft = 0; lft != i; ++lft) {
            if (xs[lft] < xs[i] && ys[lft] < ltotal) {
                ltotal = ys[lft];
            }
        }

        ui64 rtotal = numeric_limits<ui64>::max();
        for (ui64 rgt = i + 1; rgt != n; ++rgt) {
            if (xs[rgt] > xs[i] && ys[rgt] < rtotal) {
                rtotal = ys[rgt];
            }
        }

        if (ltotal != numeric_limits<ui64>::max()
            && rtotal != numeric_limits<ui64>::max()
            && ltotal + ys[i] + rtotal < total) {
            total = ltotal + ys[i] + rtotal;
        }
    }

    if (total == numeric_limits<ui64>::max()) {
        cout << -1 << endl;
    } else {
        cout << total << endl;
    }
}
