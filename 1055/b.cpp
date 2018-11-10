#include<bits/stdc++.h>

using namespace std;


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

        for (auto key : keys) {
            xs[key] = key;
            ws[key] = 1;
        }
    }

    void push_back(const T& key) {
        ++count;
        xs[key] = key;
        ws[key] = 1;
    }


    T find(const T& key, const S w = 0) {
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

        if (val1 == val2) {
            return;
        }

        --count;

        if (ws[val1] < ws[val2]) {
            std::swap(val1, val2);
        }

        xs[val2] = val1;
        ws[val2] += ws[val1];
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const DisjointSetUnion<T>& dsu) {
    for (auto x : dsu.xs) {
        os << "(" << x.first << ", " << x.second << ") ";
    } os << std::endl;

    for (auto w : dsu.ws) {
        os << "(" << w.first << ", " << w.second << ") ";
    } os << std::endl;

    std::cerr << "===========" << std::endl;

    return os;
}


using ui32 = uint32_t;
using ui64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui32 n, m, l;
    cin >> n >> m >> l;

    auto as = vector<ui64>(n, 0);
    auto dsu = DisjointSetUnion<ui64>();

    cin >> as[0];

    if (as[0] > l) {
        dsu.push_back(0);
    }

    for (ui32 i = 1; i != n; ++i) {
        cin >> as[i];

        if (as[i] > l) {
            dsu.push_back(i);

            // cerr << "Will add " << i << endl;

            if (as[i - 1] > l) {
                dsu.unite(i - 1, i);

                // cerr << "Will connect to " << i - 1 << endl;
            }
        }
    }

    for (ui32 i = 0; i != m; ++i) {
        ui32 t, p, d;

        cin >> t;

        if (t == 0) {
            // cerr << "Working on: " << t << endl;
            cout << dsu.count << endl;
        } else {
            cin >> p >> d;

            // cerr << "Working on: " << t << " " << p << " " << d << endl;

            as[p - 1] += d;

            if (as[p - 1] > l && dsu.xs.find(p - 1) == dsu.xs.end()) {
                dsu.push_back(p - 1);

                if (p - 1 != 0 && as[p - 2] > l) {
                    dsu.unite(p - 2, p - 1);
                }

                if (p != n && as[p] > l) {
                    dsu.unite(p, p - 1);
                }
            }
        }
    }
}
