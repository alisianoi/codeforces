#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    auto ns = std::vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ns[i];
    }

    int total = 0;

    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;

        int cur = 0;

        for (int j = l - 1; j < r; ++j) {
            cur += ns[j];
        }

        if (cur > 0)
            total += cur;
    }

    std::cout << total << std::endl;
}
