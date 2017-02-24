#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, k, x; cin >> n >> k >> x;

    auto xs = vector<int>(1024, 0);
    auto ys = vector<int>(1024, 0);

    for (int i = 0; i < n; ++i) {
        int a; cin >> a; ++xs[a]; ++ys[a];
    }

    for (int i = 0; i < k; ++i) {
        int before = 0;

        for (int j = 0; j < 1024; ++j) {
            const int k = j ^ x;

            if (before % 2 == 0) {
                const int amount = (xs[j] + 1) / 2;
                ys[j] -= amount;
                ys[k] += amount;
            } else {
                const int amount = xs[j] / 2;
                ys[j] -= amount;
                ys[k] += amount;
            }

            before += xs[j];
        }

        xs = ys;
    }

    for (int i = 1023; i >= 0; --i) {
        if (xs[i] != 0) {
            cout << i << " "; break;
        }
    }

    for (int i = 0; i < 1024; ++i) {
        if (xs[i] != 0) {
            cout << i << endl; break;
        }
    }
}
