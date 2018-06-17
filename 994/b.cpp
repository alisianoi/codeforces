#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    auto ps = vector<array<int, 3>>(n);

    for (int i = 0; i != n; ++i) {
      int p; cin >> p;
      ps[i] = {p, 0, i};
    }

    for (int i = 0; i != n; ++i) {
      cin >> ps[i][1];
    }

    std::sort(ps.begin(), ps.end());

    auto ans = vector<uint64_t>(n, 0);
    auto parts = vector<int>(k, 0);

    uint64_t total = 0;

    for (int i = 0; i != n; ++i) {
      ans[ps[i][2]] = total + ps[i][1];

      if (k != 0 && parts[0] < ps[i][1]) {
        total -= parts[0];
        total += ps[i][1];

        parts[0] = ps[i][1];
        sort(parts.begin(), parts.end());
      }
    }

    for (int i = 0; i != n; ++i) {
      cout << ans[i] << " ";
    } cout << endl;
}
