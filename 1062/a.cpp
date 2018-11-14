#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 n; cin >> n;

    auto as = vector<i32>(n + 2, 0);

    for (i32 i = 1; i != n + 1; ++i) {
        cin >> as[i];
    }

    as[0] = 0;
    as[n + 1] = 1001;

    i32 lft = 0, rgt = 1, max = 0;
    while (rgt != n + 2) {
        for (; rgt != n + 2 && as[rgt] == as[rgt - 1] + 1; ++rgt);

        if (rgt - lft - 2 > max) {
            max = rgt - lft - 2;
        }

        if (rgt == n + 2) {
            break;
        }

        lft = rgt;
        ++rgt;
    }

    cout << max << endl;
}
