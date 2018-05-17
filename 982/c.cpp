#include<bits/stdc++.h>

using namespace std;

int compute_weight(const std::unordered_map<int, vector<int>> &tree, vector<int> &ws, int node, int parent) {
    int total = 0;

    const auto y = tree.find(node);

    if (y == tree.end()) {
        ws[node] = 1; return 1;
    }

    const auto x = y->second;

    for (size_t i = 0; i != x.size(); ++i) {
        if (x[i] != parent) {
            total += compute_weight(tree, ws, x[i], node);
        }
    }

    ws[node] = total + 1;

    return ws[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    auto ws = vector<int>(n, 0);
    auto tree = std::unordered_map<int, vector<int>>();

    for (int i = 0; i != n - 1; ++i) {
        tree[i] = vector<int>();
    }

    for (int i = 0; i != n - 1; ++i) {
        int a, b; cin >> a >> b;

        --a; --b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    if (n % 2) {
        cout << -1 << endl;

        return 0;
    }

    compute_weight(tree, ws, 0, -1);

    size_t total = 0;
    for (int i = 1; i != n; ++i) {
        if (ws[i] % 2 == 0) {
            ++total;
        }
    }

    cout << total << endl;
}
