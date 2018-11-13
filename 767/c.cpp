#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;


class Node {
 public:

    i32 key;
    i32 val;

    vector<Node*> nodes;

    Node() : key{0}, val{0}, nodes{} {};
};

i64 dfs(
    const i32 key, const vector<Node> &nodes, vector<array<i64, 2>> &vals
) {
    i64 v = 0;

    const auto &node = nodes[key];

    for (const auto &n : node.nodes) {
        v += dfs(n->key, nodes, vals);
    }

    const auto val = v + node.val;

    vals[key] = {key, val};

    return val;
}

array<i64, 2> solve(
    const i32 key, const i64 total,
    const vector<Node> &nodes, const vector<array<i64, 2>> &vals
) {
    i64 fst = -1, snd = -1;

    for (const auto &node : nodes[key].nodes) {
        const auto res = solve(node->key, total, nodes, vals);

        if (res[0] != -1 && res[1] != -1) {
            return res;
        } else if (res[0] != -1) {
            if (fst == -1) {
                fst = res[0];
            } else {
                snd = res[0];

                return {fst, snd};
            }
        } else if (res[1] != -1) {
            if (fst == -1) {
                fst = res[1];
            } else {
                snd = res[1];

                return {fst, snd};
            }
        }
    }

    if (vals[key][1] == total / 3) {
        return {key, -1};
    }

    if (vals[key][1] == 2 * total / 3) {
        if (fst != -1) {
            return {fst, key};
        }
    }

    return {fst, snd};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 n, root;

    cin >> n;

    auto nodes = vector<Node>(n);
    auto temps = vector<array<i64, 2>>(n);

    for (i32 i = 0; i != n; ++i) {
        i32 a, t;

        cin >> a >> t;

        nodes[i].key = i;
        nodes[i].val = t;

        if (a == 0) {
            root = i;
        } else {
            nodes[a - 1].nodes.push_back(&nodes[i]);
        }
    }

    dfs(root, nodes, temps);

    const i64 total = temps[root][1];

    if (total % 3) {
        cout << "-1" << endl;   
    } else {
        const auto res = solve(root, total, nodes, temps);

        if (res[0] != -1 && res[1] != -1) {
            cout << res[0] + 1 << " " << res[1] + 1 << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}
