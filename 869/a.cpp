#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    auto xs = vector<int>(n, 0);
    auto ys = vector<int>(n, 0);
    auto zs = vector<int>(2 * n, 0);

    for (int i = 0; i != n; ++i) {
        cin >> xs[i];
        zs[i] = xs[i];
    }

    for (int i = 0; i != n; ++i) {
        cin >> ys[i];
        zs[n + i] = ys[i];
    }

    sort(zs.begin(), zs.end());

    int total = 0;
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (binary_search(zs.begin(), zs.end(), xs[i] ^ ys[j])) {
                ++total;
            }
        }
    }

    if (total % 2 == 0) {
        cout << "Karen" << endl;
    } else {
        cout << "Koyomi" << endl;
    }
}
