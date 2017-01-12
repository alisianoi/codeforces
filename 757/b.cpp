#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    uint64_t n, m; cin >> n; uint64_t limit = 100001;
    vector<uint64_t> ns = vector<uint64_t>(limit, 0);
    vector<uint64_t> vs = vector<uint64_t>(limit, 0);

    for (uint64_t i = 0; i < n; ++i) {
        cin >> m; ns[m]++;
    }

    for (uint64_t i = 2; i < limit; ++i) {
        if (vs[i] != 0) continue;

        vs[i] = 1;

        for (uint64_t j = i + i; j < limit; j += i) {
            vs[j] = 1;

            ns[i] += ns[j];
        }
    }

    if (ns[1] > 1) ns[1] = 1;

    cout << *max_element(ns.begin(), ns.end()) << endl;
}
