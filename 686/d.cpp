#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using vu32 = vector<u32>;
using graph = unordered_map<u32, vu32>;

bool is_centroid(
    const vu32 &size,
    const vu32 &largest_subtree_size,
    const u32 node,
    const u32 candidate
) {
    const auto sn = size[node];
    const auto sc = size[candidate];
    const auto lsc = largest_subtree_size[candidate];

    if (2 * (sn - sc) <= sn && 2 * lsc <= sn) {
        return true;
    }

    return false;
}

void compute_centroid(
    const graph &fwd,
    const graph &bwd,
    vu32 &size,
    vu32& largest_subtree_size,
    vu32 &centroid,
    u32 node
) {
    if (fwd.at(node).empty()) {
        size[node] = 1;
        centroid[node] = node;

        return;
    }

    for (auto child : fwd.at(node)) {
        compute_centroid(fwd, bwd, size, largest_subtree_size, centroid, child);
    }

    size[node] = 1;
    for (auto child : fwd.at(node)) {
        size[node] += size[child];
    }

    auto largest_subtree = fwd.at(node)[0];
    for (auto child : fwd.at(node)) {
        if (size[child] > size[largest_subtree]) {
            largest_subtree = child;
        }
    }

    largest_subtree_size[node] = size[largest_subtree];

    auto c = centroid[largest_subtree];

    while (!is_centroid(size, largest_subtree_size, node, c)) {
        c = bwd.at(c)[0];
    }

    centroid[node] = c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n, q;

    cin >> n >> q;

    auto fwd = unordered_map<u32, vu32>();
    auto bwd = unordered_map<u32, vu32>();

    auto size = vu32(n + 1, 0);
    auto largest_subtree_size = vu32(n + 1, 0);
    auto centroid = vu32(n + 1, 0);

    for (u32 i = 1; i != n + 1; ++i) {
        fwd[i] = {};
        bwd[i] = {};
    }

    for (u32 i = 2; i != n + 1; ++i) {
        u32 parent; cin >> parent;

        fwd[parent].push_back(i);
        bwd[i].push_back(parent);
    }

    compute_centroid(fwd, bwd, size, largest_subtree_size, centroid, 1);

    for (u32 i = 0; i != q; ++i) {
        u32 x; cin >> x;
        cout << centroid[x] << endl;
    }
}
