#include<bits/stdc++.h>

using namespace std;

pair<int, int> dfs(
    int node, int marker, vector<int>& vs,
    unordered_map<int, vector<int>>& g
) {
    vs[node] = marker;

    int edges = 0;
    int nodes = 1;

    for (auto n: g[node]) {
        int es, ns;

        edges++;

        if (vs[n] == -1) {
            std::tie(es, ns) = dfs(n, marker, vs, g);

            edges += es;
            nodes += ns;
        }
    }

    return make_pair(edges, nodes);
}

int main() {
    ios::sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;

    auto ks = vector<int>(k, 0);
    auto rs = vector<pair<int, int>>(k + 1);
    for (int i = 0; i < k; ++i) {
        cin >> ks[i]; --ks[i];
    }

    auto cities = unordered_map<int, vector<int>>();
    for (int i = 0; i < n; ++i) {
        cities[i] = vector<int>();
    }

    for (int i = 0; i < m; ++i) {
        int src, dst; cin >> src >> dst; src--; dst--;

        cities[src].push_back(dst);
        cities[dst].push_back(src);
    }

    auto vs = vector<int>(n, -1);

    for (int i = 0; i < k; ++i) {
        rs[i] = dfs(ks[i], i, vs, cities);
    }

    rs[k] = make_pair(0, 0);

    for (int i = 0; i < n; ++i) {
        if (vs[i] == -1) {
            int e, n, edges, nodes;
            std::tie(e, n) = dfs(i, k, vs, cities);

            std::tie(edges, nodes) = rs[k];

            rs[k] = make_pair(e + edges, n + nodes);
        }
    }

    int answer = 0;

    for (auto r: rs) {
        int es, ns; std::tie(es, ns) = r;
        answer += ns * (ns - 1) / 2 - es / 2;
    }

    auto here = max_element(
        rs.begin(), rs.end() - 1, [](const auto l, const auto r) {
            int le, ln, re, rn;

            std::tie(le, ln) = l;
            std::tie(re, rn) = r;

            return ln < rn;
    });

    int a, b;
    std::tie(std::ignore, a) = *here;
    std::tie(std::ignore, b) = *(rs.end() - 1);

    answer += a * b;

    cout << answer << endl;
}
