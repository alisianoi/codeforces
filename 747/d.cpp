#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int t;
    uint64_t swaps = 0, n, k; cin >> n >> k;

    auto ts = vector<uint64_t>();
    auto qs = vector<uint64_t>();

    for (uint64_t i = 0; i < n; ++i) {
        cin >> t;

        if (t < 0) {ts.push_back(i);}
    }

    if (ts.size() == 0) {
        cout << 0 << endl; return 0;
    }

    if (ts.size() > k) {
        cout << -1 << endl; return 0;
    }

    swaps++; k -= ts.size();

    for (uint64_t i = 1; i < ts.size(); ++i) {
        if (ts[i] != ts[i - 1] + 1) {
            swaps += 2; qs.push_back(ts[i] - ts[i - 1] - 1);
        }
    }

    if (*(ts.end() - 1) != n - 1) swaps++;

    sort(qs.begin(), qs.end());

    for (auto q: qs) {
        if (k >= q) {
            k -= q; swaps -= 2;
        }
    }

    auto N = n - *(ts.end() - 1) - 1;

    if (N != 0 && k >= N) {
        k -= N; --swaps;
    }

    cout << swaps << endl;
}
