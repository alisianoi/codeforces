#include <bits/stdc++.h>

using namespace std;

int main() {
    uint32_t n, m;
    uint64_t k;

    cin >> n >> m >> k;

    if (k < n) {
        cout << k + 1 << " " << 1 << endl;

        return 0;
    }

    k -= n;
    m -= 1;

    auto q = k / m;
    auto r = k % m;

    cout << n - q << " " << 1 + (q % 2 == 0 ? 1 + r : m - r) << endl;
}
