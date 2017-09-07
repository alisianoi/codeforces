#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    if (k == 0 || k == n) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }

    cout << 1 << " ";
    auto div = n / 3;

    if (k <= div) {
        cout << 2 * k;
    } else {
        int rgt = 0;
        // k > div
        if (n % 3 == 1) {
            --k;
        }

        if (n % 3 == 2) {
            --k; ++rgt;
        }

        rgt += 2 * div;
        k -= div;
        rgt -= k;

        cout << rgt;
    } cout << endl;
}
