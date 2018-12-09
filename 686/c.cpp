#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vu32 = vector<u32>;

vector<u32> build_maxval(u32 x, const u32 base = 7) {
    auto result = vector<u32>();

    --x;

    while (x >= base) {
        result.push_back(x % base);
        x /= base;
    }

    result.push_back(x);

    reverse(result.begin(), result.end());

    return result;
}

u32 solve(const vu32 &ns, const vu32 &ms, vu32 vs, u32 v, u32 i, u32 j, bool limit) {

    vs[v] = 1;

    if (i == ns.size() && j == ms.size()) {
        return 1;
    }

    u32 total = 0;

    if (i != ns.size()) {
        if (!limit) {
            for (u32 k = 0; k != vs.size(); ++k) {
                if (vs[k] == 0) {
                    total += solve(ns, ms, vs, k, i + 1, j, false);
                }
            }
        } else{
            for (u32 k = 0; k != ns[i]; ++k) {
                if (vs[k] == 0) {
                    total += solve(ns, ms, vs, k, i + 1, j, false);
                }
            }

            if (vs[ns[i]] == 0) {
                total += solve(ns, ms, vs, ns[i], i + 1, j, true);
            }
        }
    } else {
        if (j == 0) {
            for (u32 k = 0; k != ms[0]; ++k) {
                if (vs[k] == 0) {
                    total += solve(ns, ms, vs, k, i, j + 1, false);
                }
            }

            if (vs[ms[0]] == 0) {
                total += solve(ns, ms, vs, ms[0], i, j + 1, true);
            }
        } else {
            if (!limit) {
                for (u32 k = 0; k != vs.size(); ++k) {
                    if (vs[k] == 0) {
                        total += solve(ns, ms, vs, k, i, j + 1, false);
                    }
                }
            } else {
                for (u32 k = 0; k != ms[j]; ++k) {
                    if (vs[k] == 0) {
                        total += solve(ns, ms, vs, k, i, j + 1, false);
                    }
                }

                if (vs[ms[j]] == 0) {
                    total += solve(ns, ms, vs, ms[j], i, j + 1, true);
                }
            }
        }
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n, m;
    cin >> n >> m;

    auto ns = build_maxval(n);
    auto ms = build_maxval(m);

    if (ns.size() + ms.size() > 7) {
        cout << 0 << endl;

        return 0;
    }

    u32 total = 0;

    for (u32 v = 0; v != ns[0]; ++v) {
        total += solve(ns, ms, {0, 0, 0, 0, 0, 0, 0}, v, 1, 0, false);
    }

    total += solve(ns, ms, {0, 0, 0, 0, 0, 0, 0}, ns[0], 1, 0, true);

    cout << total << endl;
}
