#include<bits/stdc++.h>

using namespace std;

string cycle_shift(const string s) {
    return s[s.size() - 1] + s.substr(0, s.size() - 1);
}

int main() {
    auto result = set<string>();

    string s; cin >> s;

    for (std::size_t i = 0; i < s.size(); ++i) {
        s = cycle_shift(s);
        result.insert(s);
    }

    cout << result.size() << endl;
}
