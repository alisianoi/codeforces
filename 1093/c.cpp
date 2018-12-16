#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u64 n; cin >> n;

    auto as = vector<u64>(n, 0);

    u64 b; cin >> b;
    as[0    ] = 0;
    as[n - 1] = b;

    for (u64 i = 1; i != n / 2; ++i) {
        cin >> b;

        if (b - as[i - 1] > as[n - i]) {
            as[i        ] = b - as[n - i];
            as[n - 1 - i] = b - as[i];
        } else {
            as[i        ] = as[i - 1];
            as[n - 1 - i] = b - as[i];
        }
    }

    for (auto a : as) {
        cout << a << " ";
    } cout << endl;
}
