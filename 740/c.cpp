#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    auto ms = vector<pair<int, int>>(m);
    for (auto i = 0; i < m; ++i) {
        int l, r; cin >> l >> r; ms[i] = {l, r};
    }

    sort(ms.begin(), ms.end(), [](const auto x, const auto y) {
            int xl, xr, yl, yr;
            std::tie(xl, xr) = x;
            std::tie(yl, yr) = y;

            return xr - xl < yr - yl;
    });

    int length = ms.begin()->second - ms.begin()->first + 1;

    cout << length << endl;
    for (int i = 0; i < n; ++i)
        cout << i % length << " ";
    cout << endl;
}
