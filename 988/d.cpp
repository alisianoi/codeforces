#include<bits/stdc++.h>

using namespace std;

#include <initializer_list>
#include <unordered_map>
#include <iostream>

template <class T>
struct DisjointSetUnion {
    using S = std::size_t;

    S count;
    std::unordered_map<T, T> xs;
    std::unordered_map<T, S> ws;

    DisjointSetUnion() = default;

    template <class RandomIt>
    DisjointSetUnion(RandomIt ix, RandomIt iy) {
        count = std::distance(iy, ix);

        for (auto it = ix; it != iy; ++it) {
            xs[*it] = *it;
            ws[*it] = 1;
        }
    }

    DisjointSetUnion(std::initializer_list<T> keys) {
        count = keys.size();

        for (auto key: keys) {
            xs[key] = key;
            ws[key] = 1;
        }
    }

    void push_back(const T& key) {
        ++count;
        xs[key] = key;
        ws[key] = 1;
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

        --count;

        if (ws[val1] < ws[val2])
            std::swap(val1, val2);

        xs[val2] = val1;
        ws[val2] += ws[val1];
    }
};

// 30.897352853986263

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n; cin >> n;
    auto xs = vector<int64_t>(n, 0);

    for (int64_t i = 0; i != n; ++i) {
        cin >> xs[i];
    }

    std::sort(xs.begin(), xs.end());

    // 3 element case
    int64_t p = 1;
    for (int64_t i = 0; i != 31; ++i) {
        for (int64_t j = 0; j != n; ++j) {
            if (!binary_search(xs.begin(), xs.end(), xs[j] + p)) {
                continue;
            }

            if (!binary_search(xs.begin(), xs.end(), xs[j] + 2 * p)) {
                continue;
            }

            cout << "3" << endl;
            cout << xs[j] << " " << xs[j] + p << " " << xs[j] + 2 * p << endl;

            return 0;
        }

        p = p * 2;
    }

    // 2 element case
    p = 1;
    for (int64_t i = 0; i != 31; ++i) {

        for (int64_t j = 0; j != n; ++j) {
            if (!binary_search(xs.begin(), xs.end(), xs[j] + p)) {
                continue;
            }

            cout << "2" << endl;
            cout << xs[j] << " " << xs[j] + p << endl;

            return 0;
        }

        p = p * 2;
    }

    cout << 1 << endl;
    cout << xs[0] << endl;
}
