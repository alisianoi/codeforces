#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    auto xs = vector<int>(n + 1, 0);

    for (int i = 0; i != n / 2; ++i) {
        int x; cin >> x;
        xs[x] = 1;
    }

    int bs = 0, ws = 0, j = 0;
    for (int i = 1; i != n + 1; i += 2) {
        for (++j; xs[j] != 1; ++j);

        bs += std::abs(j - i);
    }

    j = n + 1;
    for (int i = n; i != 0; i -= 2) {
        for (--j; xs[j] != 1; --j);

        ws += std::abs(i - j);
    }

    cout << std::min({bs, ws}) << endl;
}
