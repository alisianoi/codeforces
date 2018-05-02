#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n; cin >> n;

    std::vector<std::vector<size_t>> as(n);

    for (size_t i = 0; i != n; ++i) {
        size_t l, r; cin >> l >> r;
        as[i] = std::vector<size_t>{l, r, i + 1};
    }

    std::sort(
        as.begin(), as.end(), [](const auto &lhs, const auto &rhs) {
            if (lhs[0] < rhs[0]) {
                return true;
            }

            if (lhs[0] == rhs[0] && lhs[1] > rhs[1]) {
                return true;
            }

            return false;
        }
    );

    for (size_t i = 0; i + 1 != n; ++i) {
        if (as[i][0] <= as[i + 1][0] && as[i + 1][1] <= as[i][1]) {
            cout << as[i + 1][2] << " " << as[i][2] << endl;

            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}
