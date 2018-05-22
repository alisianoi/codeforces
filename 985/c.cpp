#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, k, l;
    cin >> n >> k >> l;

    auto xs = vector<int64_t>(n * k, 0);

    for (int64_t i = 0; i != n * k; ++i) {
        cin >> xs[i];
    }

    std::sort(xs.begin(), xs.end());

    int64_t volume = 0;

    auto lft = xs.begin();
    auto mid = std::upper_bound(xs.begin(), xs.end(), xs[0] + l);
    auto rgt = mid;

    while (n != 0 && lft != mid) {

        int64_t m = k;
        volume += *lft; ++lft;

        --m;

        while (m != 0 && std::distance(lft, mid) >= n) {
            --m; ++lft;
        }

        while (m != 0 && rgt != xs.end()) {
            --m; ++rgt;
        }

        if (m != 0) {
            volume = 0;
            break;
        }

        --n;
    }

    if (n != 0) {
        cout << 0 << endl;
    } else {
        cout << volume << endl;
    }
}
