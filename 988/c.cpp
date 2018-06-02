#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t k; cin >> k;
    auto ys = vector<array<int64_t, 3>>();

    for (int64_t i = 0; i != k; ++i) {
        int64_t n; cin >> n;
        auto xs = vector<int64_t>(n, 0);

        int64_t t = 0;
        for (int64_t j = 0; j != n; ++j) {
            cin >> xs[j];

            t += xs[j];
        }

        for (int64_t j = 0; j != n; ++j) {
            ys.push_back({t - xs[j], i + 1, j + 1});
        }
    }

    std::sort(ys.begin(), ys.end());

    size_t j = 0; bool ok = false;
    for (size_t i = 1; i != ys.size(); ++i) {
        if (ys[j][0] != ys[i][0]) {
            j = i;
        } else {
            if (ys[j][1] != ys[i][1]) {
                cout << "YES" << endl;
                cout << ys[j][1] << " " << ys[j][2] << endl;
                cout << ys[i][1] << " " << ys[i][2] << endl;

                ok = true;
                break;
            }
        }
    }

    if (!ok) {
        cout << "NO" << endl;
    }
}
