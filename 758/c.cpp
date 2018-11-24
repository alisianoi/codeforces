#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 n, m, x, y; i64 k;

    cin >> n >> m >> k >> x >> y;

    i64 minq, maxq, serq;

    if (n == 1 || n == 2) {
        const auto size = n * m;

        const auto q = k / size;
        const auto r = k % size;

        minq = q;
        maxq = r == 0 ? minq : minq + 1;

        const auto sask = (x - 1) * m + y;

        if (sask <= r) {
            serq = maxq;
        } else {
            serq = minq;
        }
    } else {
        const auto size = (n - 1) * m;

        const auto q = k / size;
        const auto r = k % size;

        maxq = q == 0 ? 1 : q;
        minq = q / 2;

        if (q != 0 && r > m) {
            ++maxq;
        }

        if (x == 1) {
            serq = (q + 1) / 2;
        } else if (x == n) {
            serq = q / 2;
        } else {
            serq = q;
        }

        if (q % 2) {
            // from last to first
            if (r >= m) {
                ++minq;
            }

            if (n * m - (x - 1) * m - (m - y) <= r) {
                ++serq;
            }
        } else {
            // from first to last
            if ((x - 1) * m + y <= r) {
                ++serq;
            }
        }
    }

    cout << maxq << " " << minq << " " << serq << endl;
}
