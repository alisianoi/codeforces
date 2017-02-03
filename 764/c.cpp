#include<bits/stdc++.h>

using namespace std;

int dfs(
    unordered_map<int, set<int>>& gs,
    vector<int>& cs, vector<int>& vs,
    int node
) {
    vs[node] = 1;

    for (auto n: gs[node]) {
        if (vs[n] == 1) {continue;}

        if (cs[n] != cs[node]) {
            return 0;
        }

        if (dfs(gs, cs, vs, n) == 0) {
            return 0;
        }
    }

    return 1;
}

int try_node(
    unordered_map<int, set<int>>& gs,
    vector<int>& cs, int node
) {
    auto vs = vector<int>(cs.size(), 0);

    vs[node] = 1;

    for (auto n: gs[node]) {
        if (dfs(gs, cs, vs, n) == 0) {
            return 0;
        }
    }

    return 1;
}


int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto gs = unordered_map<int, set<int>>();
    auto cs = vector<int>(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int src, dst; cin >> src >> dst;

        src--; dst--;

        if (gs.find(src) == gs.end()) {
            gs[src] = set<int>();
        }

        if (gs.find(dst) == gs.end()) {
            gs[dst] = set<int>();
        }

        gs[src].insert(dst);
        gs[dst].insert(src);
    }

    for (int i = 0; i < n; ++i) {
        cin >> cs[i];
    }

    for (int src = 0; src < n; ++src) {
        for (auto dst: gs[src]) {
            if (cs[src] != cs[dst]) {
                if (try_node(gs, cs, src) == 1) {
                    cout << "YES" << endl;
                    cout << src + 1 << endl;

                    return 0;
                }

                if (try_node(gs, cs, dst) == 1) {
                    cout << "YES" << endl;
                    cout << dst + 1 << endl;

                    return 0;
                }

                cout << "NO" << endl;

                return 0;
            }
        }
    }

    cout << "YES" << endl; cout << 1 << endl;
}
