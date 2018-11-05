#include <bits/stdc++.h>

using namespace std;

bool check(map<int, vector<int>>& hatred, vector<int>& players) {
    for (auto i = players.begin(); i != players.end() - 1; ++i) {
        for (auto j = i + 1; j != players.end(); ++j) {
            if (find(hatred[*i].begin(), hatred[*i].end(), *j) != hatred[*i].end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string s, t;
    int n, m; cin >> n >> m;

    auto decode = vector<string>();
    auto encode = map<string, int>();
    auto hatred = map<int, vector<int>>();

    for (int i = 0; i != n; ++i) {
        cin >> s;

        decode.push_back(s);
        encode[s] = i;
        hatred[i] = vector<int>();
    }

    getline(cin, s, '\n');

    for (int i = 0; i != m; ++i) {
        getline(cin, s, ' ');
        getline(cin, t, '\n');

        auto si = encode[s];
        auto ti = encode[t];

        hatred[si].push_back(ti);
        hatred[ti].push_back(si);
    }

    auto maxteam = vector<int>();

    for (int i = 1; i != pow(2, n); ++i) {

        auto team = vector<int>();

        for (auto N = i, j = 0; N != 0; N /= 2, ++j) {
            if (N % 2) {
                team.push_back(j);
            }
        }

        if (check(hatred, team)) {
            if (team.size() > maxteam.size()) {
                maxteam = team;
            }
        }
    }

    auto names = vector<string>();

    for (auto player : maxteam) {
        names.push_back(decode[player]);
    }

    sort(names.begin(), names.end());

    cout << names.size() << endl;

    for (auto name : names) {
        cout << name << endl;
    }
}
