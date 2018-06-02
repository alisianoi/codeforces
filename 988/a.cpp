#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    int n, k; cin >> n >> k;

    auto ys = vector<int>();
    auto xs = vector<array<int, 2>>(n);
    for (int i = 0; i != n; ++i) {
        cin >> x;
        xs[i] = {x, i + 1};
    }

    std::sort(xs.begin(), xs.end());

    int j = 0;
    ys.push_back(xs[0][1]);
    for (int i = 1; i != n; ++i) {
        if (ys.size() == k) {
            break;
        }

        if (xs[i][0] != xs[j][0]) {
            ys.push_back(xs[i][1]);
            j = i;
        }
    }

    if (ys.size() != k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        for (auto y: ys) {
            cout << y << " ";
        } cout << endl;
    }
}
