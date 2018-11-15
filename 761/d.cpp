#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u64 n, l, r;

    cin >> n >> l >> r;

    auto as = vector<u64>(n, 0);
    auto bs = vector<u64>(n, 0);
    auto ps = vector<u64>(n, 0);

    for (u32 i = 0; i != n; ++i) {
        cin >> as[i];
    }

    for (u32 i = 0; i != n; ++i) {
        cin >> ps[i];
    }

    // Assume c_i = i, i.e. all distinct
    for (u32 i = 0; i != n; ++i) {
        bs[i] = as[i] + ps[i];
    }

    const auto minb = *std::min_element(bs.begin(), bs.end());

    for (u32 i = 0; i != n; ++i) {
        bs[i] -= (minb - l);
    }

    const auto maxb = *std::max_element(bs.begin(), bs.end());

    if (maxb > r) {
        cout << "-1" << endl;
    } else {
        for (const auto b : bs) {
            cout << b << " ";
        } cout << endl;
    }
}
