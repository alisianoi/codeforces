#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n; string s; cin >> s;

    unordered_map<char, int> ds = {
        {'L', 1}, {'R', 1}, {'U', 1}, {'D', 1}
    };

    int total = 0;

    for (auto c = s.begin(); c != s.end(); ++c) {
        if (ds[*c] == 0) {
            total++;

            ds['L'] = 1;
            ds['R'] = 1;
            ds['U'] = 1;
            ds['D'] = 1;
        }

        if (*c == 'R') {
            ds['L'] = 0;
        } else if (*c == 'L') {
            ds['R'] = 0;
        } else if (*c == 'U') {
            ds['D'] = 0;
        } else {
            ds['U'] = 0;
        }
    }

    cout << total + 1 << endl;
}
