#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    std::string s, t; cin >> s >> t;

    auto subs = unordered_map<char, char>();

    for (uint64_t i = 0; i < s.size(); ++i) {
        const auto x = subs.find(s[i]);
        const auto y = subs.find(t[i]);

        if (x == subs.end() && y == subs.end()) {
            subs[s[i]] = t[i];
            subs[t[i]] = s[i];
        } else if (x != subs.end() && y != subs.end()) {
            if (x->second != y->first || x->first != y->second) {
                cout << -1 << endl; return 0;
            }
        } else {
            cout << -1 << endl; return 0;
        }

    }

    for (auto it = subs.begin(); it != subs.end();) {
        if (it->first == it->second) {
            it = subs.erase(it);
        } else {
            ++it;
        }
    }

    cout << subs.size() / 2 << endl;
    for (const auto& x: subs) {
        if (x.first < x.second)
            cout << x.first << " " << x.second << endl;
    }
}
