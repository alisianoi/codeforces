#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;

    int l = 0, r = 0;

    int result = 1; m -= n;

    while (m != 0) {
        if (l == k - 1 && r == n - k) break;

        if (m < l + r + 1) break;

        m = m - l - r - 1; result++;

        if (l != k - 1) l++;
        if (r != n - k) r++;
    }

    result += m / n;

    cout << result << endl;
}
