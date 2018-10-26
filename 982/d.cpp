#include<bits/stdc++.h>

using namespace std;


template<typename T>
class DisjointSetUnion {
public:
    using W = std::size_t;

    std::size_t sets;

    std::unordered_map<T, T> ts;
    std::unordered_map<T, W> ws;

    std::set<std::pair<std::size_t, T>> hs;

    DisjointSetUnion() {
        sets = 0;

        ts = std::unordered_map<T, T>();
        ws = std::unordered_map<T, W>();

        hs = std::set<std::pair<std::size_t, T>>();
    }

    void push_back(const T& t) {
        ++sets;

        ts[t] = t;
        ws[t] = 1;

        // cerr << "insert (" << 1 << ", " << t << ")" << endl;
        hs.insert(std::make_pair(1, t));
    }

    typename unordered_map<T, T>::iterator
    find(const T& t) {
        if (ts.find(t) == ts.end()) {
            return ts.end();
        }

        return ts.find(find(t, 0));
    }

    void unite(const T& t1, const T& t2) {
        typename unordered_map<T, T>::iterator h1 = find(t1);
        typename unordered_map<T, T>::iterator h2 = find(t2);

        if (h1 == end() || h2 == end() || h1 == h2) {
            return;
        }

        sets -= 1;

        // if (ws[h1->first] < ws[h2->first]) {
        //     const auto fst = h1->first;
        //     const auto snd = h1->second;
        //     h1->first = h2->first;
        //     h1->second = h2->second;
        //     h2->first = fst;
        //     h2->second = snd;
        //     // std::iter_swap(h1, h2);
        // }

        // cerr << "erase (" << ws[h1->first] << ", " << h1->first << ")" << endl;
        // cerr << "erase (" << ws[h2->first] << ", " << h2->first << ")" << endl;
        hs.erase(std::make_pair(ws[h1->first], h1->first));
        hs.erase(std::make_pair(ws[h2->first], h2->first));

        ts[h2->first] = h1->first;
        ws[h1->first] += ws[h2->first];

        // cerr << "insert (" << ws[h1->first] << ", " << h1->first << ")" << endl;
        hs.insert(std::make_pair(ws[h1->first], h1->first));

        // cerr << "size equals size? " << (sets == hs.size()) << endl;
    }

    typename unordered_map<T, T>::iterator end() {
        return ts.end();
    }

private:
    T find(const T& t, const W& w) {
        if (ts[t] == t) {
            ws[t] += w;

            return t;
        }

        ws[t] -= w;
        return ts[t] = find(ts[t], ws[t]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto dsu = DisjointSetUnion<int>();

    std::size_t N = 0; cin >> N;
    vector<int> xs(N, 0), ys(N, 0);
    auto zs = std::unordered_map<int, vector<std::size_t>>();

    for (std::size_t i = 0; i != N; ++i) {
        int x; cin >> x;

        xs[i] = x;
        ys[i] = x;

        if (zs.find(x) != zs.end()) {
            zs[x].push_back(i);
        } else {
            zs[x] = {i};
        }
    }

    std::sort(xs.begin(), xs.end());

    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    std::uint64_t segments = 0;
    std::uint64_t min_travel_speed = 0;

    for (auto x : xs) {
        // cerr << "=== working with " << x << endl;
        for (auto z = zs[x].begin(); z != zs[x].end(); ++z) {
            const auto i = *z;

            dsu.push_back(i);

            if (i != 0 && ys[i - 1] <= x) {
                dsu.unite(i, i - 1);
            }
            if (i != ys.size() && ys[i + 1] <= x) {
                dsu.unite(i, i + 1);
            }
        }

        if (dsu.hs.begin()->first == std::prev(dsu.hs.end())->first) {
            if (dsu.hs.size() > segments) {
                segments = dsu.hs.size();
                min_travel_speed = x + 1;
            }
        }
    }

    cout << min_travel_speed << endl;
}
