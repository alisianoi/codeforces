#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string s, p;

    auto ss = unordered_map<
        string, multiset<int, std::greater<int>>
    >();

    auto ps = unordered_map<
        string, multiset<int, std::greater<int>>
    >();

    int k, n, a; cin >> k >> n;

    for (int i = 0; i < k; ++i) {
        cin >> s >> a;

        p = s; reverse(p.begin(), p.end());

        if (p.compare(s) == 0) {
            auto x = ps.find(s);

            if (x == ps.end()) {
                ps[s] = {a};
            } else {
                x->second.insert(a);
            }
        } else {
            auto x = ss.find(s);

            if (x == ss.end()) {
                ss[s] = {a};
            } else {
                x->second.insert(a);
            }
        }
    }

    uint64_t total = 0;

    for (auto it = ss.begin(); it != ss.end(); ++it) {
        auto s0 = it->first;
        auto s1 = s0;

        reverse(s1.begin(), s1.end());

        auto loc = ss.find(s1);

        if (loc == ss.end()) continue;

        auto& as0 = it->second;
        auto& as1 = loc->second;

        auto it0 = as0.begin();
        auto it1 = as1.begin();

        while (it0 != as0.end() && it1 != as1.end()) {
            const auto cur = *it0 + *it1;
            if (cur >= 0) {
                total += cur;
                it0 = as0.erase(it0);
                it1 = as1.erase(it1);
            } else {
                break;
            }
        }
    }

    int adj = 0;

    for (auto it = ps.begin(); it != ps.end(); ++it) {
        auto& as0 = it->second;
        auto iq = as0.begin();

        while (iq != as0.end() && next(iq) != as0.end()) {
            const auto cur = *iq + *next(iq);
            if (cur >= 0) {

                if (*next(iq) < adj) adj = *next(iq);

                total += cur;

                iq = as0.erase(iq);
                iq = as0.erase(iq);
            } else {
                break;
            }
        }
    }

    auto m = max_element(
        ps.begin(), ps.end(), [](auto& l, auto& r) -> bool {
            const auto la = *l.second.begin();
            const auto ra = *r.second.begin();

            return la < ra;
        });

    if (m != ps.end()) {
        const auto t = *m->second.begin();

        if (t > abs(adj)) {
            total += t;
        } else {
            total += abs(adj);
        }
    }

    cout << total << endl;
}
