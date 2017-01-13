#include<bits/stdc++.h>

using namespace std;

// based on tourist's solution

int main() {
    ios::sync_with_stdio(0);

    int n; int m; cin >> n >> m;

    auto xs = vector<vector<int>>(m);

    for (int i = 0; i < n; ++i) {
        int l; cin >> l;

        for (int j = 0; j < l; ++j) {
            int x; cin >> x;

            xs[x - 1].push_back(i);
        }
    }

    // performs lexicographic sort of vectors, ie
    // identical clusters are now near each other.
    sort(xs.begin(), xs.end());

    uint64_t total = 1, t = 1;

    for (int i = 1; i < m; ++i) {
        if (xs[i - 1] == xs[i]) {
            // i - 1 and i are identical clusters => can permute them
            t++;
        } else {
            t = 1;
        }

        total = total * t % 1000000007;
    }

    cout << total << endl;
}
