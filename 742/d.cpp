#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

using graph = unordered_map<u64, vector<u64>>;


void dfs(graph &fs, u32 f, vector<u32> &ms, u32 m) {

    ms[f] = m;

    for (const auto &n : fs[f]) {
        if (ms[n] != 0) {
            continue;
        }

        dfs(fs, n, ms, m);
    }
}


vector<u32> build_connected_components(graph &fs) {
    const auto n = fs.size();
    auto result = vector<u32>(n + 1, 0);

    for (u32 i = 1; i != n + 1; ++i) {
        if (result[i] != 0) {
            continue;
        }

        dfs(fs, i, result, i);
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n, m, w;
    cin >> n >> m >> w;

    auto ws = vector<u32>(n, 0);
    auto bs = vector<u32>(n, 0);

    for (auto &w : ws) {
        cin >> w;
    }

    for (auto &b : bs) {
        cin >> b;
    }

    u32 lhs, rhs;
    auto fs = graph();
    for (u32 i = 1; i != n + 1; ++i) {
        fs[i];
    }

    for (u32 i = 0; i != m; ++i) {
        cin >> lhs >> rhs;

        fs[lhs].push_back(rhs);
        fs[rhs].push_back(lhs);
    }

    const auto cc = build_connected_components(fs);
    auto groups = vector<vector<array<u64, 2>>>();

    for (u32 i = 1; i != n + 1; ++i) {
        if (cc[i] != i) {
            continue;
        }

        u64 beauty = 0;
        u64 weight = 0;

        auto group = vector<array<u64, 2>>();

        for (u32 j = i; j != n + 1; ++j) {
            if (cc[j] == i) {
                const auto w = ws[j - 1];
                const auto b = bs[j - 1];

                group.push_back({w, b});

                weight += w;
                beauty += b;
            }
        }

        group.push_back({weight, beauty});

        sort(group.begin(), group.end(), [] (const auto &lhs, const auto &rhs) {
            if (lhs[0] < rhs[0]) {
                return true;
            }

            if (lhs[0] == rhs[0] && lhs[1] > rhs[1]) {
                return true;
            }

            return false;
        });

        auto best = vector<array<u64, 2>>();

        u32 a = 0;
        best.push_back(group[a]);

        for (u32 b = 1; b != group.size(); ++b) {
            if (group[b][1] <= group[a][1]) {
                continue;
            }

            best.push_back(group[b]);
            a = b;
        }

        groups.push_back(best);
    }
    // 
    // cerr << "Here are the components: " << endl;
    // for (auto x : cc) {
    //     cerr << x << " ";
    // } cerr << endl;
    //
    // cerr << "Here are the groups:" << endl;
    // for (auto group : groups) {
    //     for (auto g : group) {
    //         cerr << "(" << g[0] << ", " << g[1] << ") ";
    //     } cerr << endl;
    // }

    const auto gs = groups.size();
    auto dp = vector<vector<u64>>();

    for (u32 i = 0; i != gs + 1; ++i) {
        dp.push_back(vector<u64>(w + 1, 0));
    }

    for (u32 i = 1; i != gs + 1; ++i) {
        const auto &group = groups[i - 1];

        for (u32 j = 1; j != w + 1; ++j) {

            dp[i][j] = dp[i - 1][j];

            for (u32 k = 0; k != group.size(); ++k) {
                if (group[k][0] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - group[k][0]] + group[k][1]);
                }
            }
        }
    }

    cout << dp[gs][w] << endl;
}
