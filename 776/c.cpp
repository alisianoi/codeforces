#include<bits/stdc++.h>

using namespace std;

// log2(10 ** 14) = 46.5 -> 47
int main() {
    ios_base::sync_with_stdio(0);
    uint64_t answer = 0;
    int n, k; cin >> n >> k;

    auto ns = vector<int64_t>(n + 1, 0);

    ns[0] = 0;
    cin >> ns[1];
    for (int i = 1; i != n; ++i) {
        int x; cin >> x; ns[i + 1] = ns[i] + x;
    }

    int pn = 0;
    if (k == 1) {
        pn = 1;
    } else if (k == -1) {
        pn = 2;
    } else {
        pn = ceil(log(1E14) / log(abs(k))) + 1;
    }

    auto powers = vector<int64_t>(pn, 0);
    powers[0] = 1;
    if (pn != 1) {
        powers[1] = k;

        for (int i = 2; i != pn; ++i) {
            powers[i] = powers[i - 1] * k;
        }
    }

    auto prefixes = map<int64_t, uint64_t>();

    for (int i = n; i != -1; --i) {
        for (int64_t power: powers) {
            if (prefixes.find(ns[i] + power) != prefixes.end()) {
                answer += prefixes[ns[i] + power];
            }
        }

        ++prefixes[ns[i]];
    }

    cout << answer << endl;
}
