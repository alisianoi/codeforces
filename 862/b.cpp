#include<bits/stdc++.h>

using namespace std;

pair<int, int> dfs(
    map<int, vector<int>>& graph, const int node,
    const int depth, int n1, int n2,
    vector<int>& visited
) {
    visited[node] = depth % 2;

    vector<int>& nodes = graph[node];

    for (auto dst = nodes.begin(); dst != nodes.end(); ++dst) {
        if (visited[*dst] == -1) {
            int m1, m2;
            tie(m1, m2) = dfs(graph, *dst, depth + 1, 0, 0, visited);

            n1 += m1;
            n2 += m2;
        }
    }

    if (depth % 2 == 0) {
        return make_pair(n1 + 1, n2);
    } else {
        return make_pair(n1, n2 + 1);
    }
}

int main() {
    int n; cin >> n; int root = -1;

    auto graph = map<int, vector<int>>();

    for (int i = 0; i != n - 1; ++i) {
        int src, dst; cin >> src >> dst; root = src;

        if (graph.find(src) == graph.end()) {
            graph[src] = vector<int>();
        }

        graph[src].push_back(dst);

        if (graph.find(dst) == graph.end()) {
            graph[dst] = vector<int>();
        }

        graph[dst].push_back(src);
    }

    auto visited = vector<int>(100001, -1);

    int n1, n2;
    tie(n1, n2) = dfs(
        graph, root, 0, 0, 0, visited
    );

    uint64_t total = 0;
    for (auto node = graph.begin(); node != graph.end(); ++node) {
        auto src = node->first; vector<int>& nodes = node->second;

        if (visited[src] == 0) {
            total += n2 - nodes.size();
        } else {
            total += n1 - nodes.size();
        }
    }

    cout << total / 2 << endl;
}
