#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, m; cin >> n >> m;

    auto as = vector<uint64_t>(n, 0);

    for (uint64_t i = 0; i != n; ++i) {
        cin >> as[i];
    }

    for (uint64_t i = 1; i != n; ++i) {
        as[i] += as[i - 1];
    }

    for (uint64_t i = 0; i != m; ++i) {
        uint64_t b, f, k; cin >> b;

        auto d = lower_bound(as.begin(), as.end(), b);

        f = std::distance(as.begin(), d) + 1;
        k = d == as.begin() ? b : b - *(d - 1);

        cout << f << " " << k << endl;
    }
}
