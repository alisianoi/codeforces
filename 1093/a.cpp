#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 t; cin >> t;

    for (i32 i = 0; i != t; ++i) {
        i32 n; cin >> n;

        if (n < 7) {
            cout << 1 << endl;
        } else {
            cout << n / 7 + (n % 7 == 0 ? 0 : 1) << endl;
        }
    }
}
