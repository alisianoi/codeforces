#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 n, k; cin >> n >> k;

    if (k > n / 2) {
        k = n - k;
    }

    i32 x = 1;
    i32 r = 0;
    i32 c = 0;
    u64 t = 1;

    for (i32 i = 0; i != n; ++i) {
        x += k;

        if (x <= n + 1) {
            c = 2 * r;
        } else {
            c = 2 * r + 1;

            ++r;

            x = x - n;
        }

        t += c + 1;

        cout << t << " ";
    } cout << endl;
}
