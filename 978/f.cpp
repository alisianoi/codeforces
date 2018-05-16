#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, k; cin >> n >> k;

    auto rs = vector<vector<uint64_t>>(n, vector<uint64_t>(2, 0));
    auto qs = map<uint64_t, vector<uint64_t>>();

    for (uint64_t i = 0; i != n; ++i) {
        uint64_t r; cin >> r;

        rs[i][0] = r;
        rs[i][1] = i;
    }

    for (uint64_t i = 0; i != n; ++i) {
        qs[i] = vector<uint64_t>();
    }

    for (uint64_t i = 0; i != k; ++i) {
        uint64_t a, b; cin >> a >> b;

        --a; --b;

        if (rs[a][0] == rs[b][0]) {
            continue;
        }

        if (rs[a][0] > rs[b][0]) {
            qs[a].push_back(b);
        } else {
            qs[b].push_back(a);
        }
    }

    sort(
        rs.begin(), rs.end(), [](const auto &lft, const auto &rgt) {
            if (lft[0] < rgt[0]) {
                return true;
            }

            return false;
        }
    );

    auto ts = vector<uint64_t>(n, 0);
    auto as = vector<uint64_t>(n, 0);

    int j = 0;
    for (uint64_t i = 1; i != n; ++i) {
        ts[i] = ts[i - 1];

        if (rs[i - 1][0] != rs[i][0]) {
            ts[i] += (i - j);

            j = i;
        }
    }

    for (uint64_t i = 0; i != n; ++i) {
        uint64_t j = rs[i][1];

        if (qs[j].size() >= ts[i]) {
            as[j] = 0;
        } else {
            as[j] = ts[i] - qs[j].size();
        }
    }

    for (uint64_t i = 0; i != n; ++i) {
        cout << as[i] << " ";
    } cout << endl;
}
