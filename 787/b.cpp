#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i != m; ++i) {
        int k; cin >> k;

        if (k == 0) continue;

        auto ks = vector<int>(k, 0);

        for (int j = 0; j != k; ++j) {
            cin >> ks[j];
        }

        sort(ks.begin(), ks.end());

        bool fail = true;

        auto lft = ks.begin();
        auto rgt = ks.end() - 1;

        while (lft != rgt && *lft < 0 && 0 < *rgt) {
            if (*lft + *rgt == 0) {
                fail = false;

                break;
            }

            if (abs(*lft) < *rgt) {
                rgt--;
            } else {
                lft++;
            }
        }

        if (fail) {
            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;
}
