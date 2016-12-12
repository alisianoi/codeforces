#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, x; cin >> n >> x;

    auto as = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

    sort(as.begin(), as.end());

    uint64_t total = 0;

    for (auto fst = as.begin(); fst != as.end(); ++fst) {
        int p = x ^ (*fst);

        auto lb = lower_bound(fst + 1, as.end(), p);
        auto ub = upper_bound(fst + 1, as.end(), p);

        total += distance(lb, ub);
    }

    cout << total << endl;
}
