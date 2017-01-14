#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int64_t n, c, d; cin >> n;

    int64_t delta = 0;

    int64_t fborder = std::numeric_limits<int64_t>::max();
    int64_t sborder = std::numeric_limits<int64_t>::min();

    for (int64_t i = 0; i < n; ++i) {
        cin >> c >> d;

        if (d == 1) {
            fborder = min(fborder, delta);
        } else {
            sborder = max(sborder, delta);
        }

        delta += c;
    }

    if (sborder >= fborder) {
        cout << "Impossible" << endl;
        return 0;
    }

    if (sborder == std::numeric_limits<int64_t>::min()) {
        cout << "Infinity" << endl;
        return 0;
    }

    cout << 1899 - sborder + delta << endl;
}
