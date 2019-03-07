#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n; cin >> n;
    auto as = vector<u32>(n, 0);

    for (u32 i = 0; i != n; ++i) {
        cin >> as[i];
    }

    if (n == 2) {
        cout << 0 << endl;
        return 0;
    }

    std::sort(as.begin(), as.end());

    auto lft_diff = as[1] - as[0];
    auto rgt_diff = as[n - 1] - as[n - 2];

    if (lft_diff > rgt_diff) {
        cout << as[n - 1] - as[1] << endl;
    } else {
        cout << as[n - 2] - as[0] << endl;
    }
}
