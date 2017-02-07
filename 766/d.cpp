#include<bits/stdc++.h>

using namespace std;

template <class T>
struct DisjointSetUnion {
    using S = std::size_t;

    std::unordered_map<T, T> xs;
    std::unordered_map<T, S> ws;

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

        if (ws[val1] < ws[val2])
            std::swap(val1, val2);

        xs[val2] = val1;
        ws[val2] += ws[val1];
    }
};

vector<string> split(const string& str, const string& sep=" ") {
    auto result = vector<string>{};
    string::size_type lft = 0, rgt = 0;

    do {
        rgt = str.find(sep, lft);

        result.push_back(str.substr(lft, rgt - lft));

        lft = rgt + sep.size();
    } while (rgt != string::npos);

    return result;
}

int main() {
    ios::sync_with_stdio(0);

    auto syn = DisjointSetUnion<string>();
    auto ant = unordered_map<string, string>();

    int n, m, q; cin >> n >> m >> q;

    string tmp;
    getline(cin, tmp);

    string words; getline(cin, words);

    string::size_type lft = 0, rgt = 0;

    do {
        rgt = words.find(" ", lft);

        string s = words.substr(lft, rgt - lft);

        syn.push_back(s);
        ant[s] = "";

        lft = rgt + 1;
    } while (rgt != string::npos);

    for (int i = 0; i < m; ++i) {
        int x; string s, t; cin >> x >> s >> t;

        auto ms = syn.find(s);
        auto mt = syn.find(t);

        if (x == 1) {
            if (ant[ms] == mt) {
                cout << "NO" << endl;
            } else {
                syn.unite(ms, mt);

                auto ams = ant[ms];
                auto amt = ant[mt];

                if (ams != "" && amt != "") {
                    syn.unite(ams, amt);

                    ams = syn.find(ams);

                    ant[ms] = ams;
                    ant[mt] = ams;

                    ant[ams] = syn.find(ms);
                    ant[amt] = syn.find(ms);
                } else if (ams != "") {
                    ant[mt] = ams;

                    ant[ams] = syn.find(ms);
                } else if (amt != "") {
                    ant[ms] = amt;

                    ant[amt] = syn.find(ms);
                }

                cout << "YES" << endl;
            }
        } else {
            if (ms == mt) {
                cout << "NO" << endl;
            } else {
                auto ams = ant[ms];
                auto amt = ant[mt];

                if (ams == "" && amt == "") {
                    ant[ms] = mt;
                    ant[mt] = ms;
                } else if (ams != "" && amt != "") {
                    syn.unite(ms, amt);
                    syn.unite(mt, ams);

                    ant[ms] = syn.find(mt);
                    ant[mt] = syn.find(ms);

                } else if (ams != "") {
                    syn.unite(ams, mt);

                    ant[ms] = syn.find(mt);
                } else if (amt != "") {
                    syn.unite(amt, ms);

                    ant[mt] = syn.find(ms);
                }

                cout << "YES" << endl;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        string s, t; cin >> s >> t;

        auto ms = syn.find(s);
        auto mt = syn.find(t);

        if (ms == mt) {
            cout << 1 << endl;
        } else if (ant[ms] == mt) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
}
