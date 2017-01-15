#include<bits/stdc++.h>

using namespace std;

template <class T>
struct DisjointSetUnion {
    using S = std::size_t;

    std::unordered_map<T, T> xs;
    std::unordered_map<T, S> ws;

    S total = 0;

    DisjointSetUnion() = default;

    template <class RandomIt>
    DisjointSetUnion(RandomIt ix, RandomIt iy) {
        for (auto it = ix; it != iy; ++it) {
            xs[*it] = *it;
            ws[*it] = 1;
        }
    }

    DisjointSetUnion(std::initializer_list<T> keys) {
        for (auto key: keys) {
            xs[key] = key;
            ws[key] = 1;
        }
    }

    void push_back(const T& key) {
        xs[key] = key;
        ws[key] = 1;
        total++;
    }

    T find(const T& key, const S w=0) {
        if (xs[key] == key) {
            ws[key] += w;

            return key;
        }

        ws[xs[key]] -= ws[key];
        return xs[key] = find(xs[key], ws[key]);
    }

    void unite(const T& key1, const T& key2) {
        auto val1 = find(key1);
        auto val2 = find(key2);

        if (val1 == val2) return;

        total--;

        if (ws[val1] < ws[val2])
            std::swap(val1, val2);

        xs[val2] = val1;
        ws[val2] += ws[val1];
    }

    int get_total() {return this->total;}
};

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ds = DisjointSetUnion<int>();

    for (int i = 1; i <= n; ++i) {
        ds.push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        int j; cin >> j; ds.unite(i, j);
    }

    cout << ds.get_total() << endl;
}
