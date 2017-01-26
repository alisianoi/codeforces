#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    auto ts = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> ts[i];
    }

    auto ps = vector<int>(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + 20;

        auto ago90 = distance(
            ts.begin(), lower_bound(ts.begin(), ts.end(), ts[i] - 89)
        );

        ps[i + 1] = min(ps[i + 1], 50 + ps[ago90]);

        auto ago1440 = distance(
            ts.begin(), lower_bound(ts.begin(), ts.end(), ts[i] - 1439)
        );

        ps[i + 1] = min(ps[i + 1], 120 + ps[ago1440]);

        cout << ps[i + 1] - ps[i] << endl;
    }
}
