#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n;

    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << endl;

        return 0;
    } else {
        const auto old_n = n;

        for (uint64_t d = 3; d * d <= n; ++d) {
            if (n % d == 0) {
                n -= d;

                break;
            }
        }

        if (n == old_n) {
            cout << 1 << endl;
        } else {
            cout << n / 2 + 1 << endl;
        }
    }
}
