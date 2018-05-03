#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    set<set<char>> ds;

    for (int i = 0; i != n; ++i) {
        string s;
        cin >> s;

        ds.insert(set<char>(s.begin(), s.end()));
    }

    cout << ds.size() << endl;
}
