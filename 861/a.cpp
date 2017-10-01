#include<bits/stdc++.h>

using namespace std;

int main() {
    uint64_t n, k; cin >> n >> k;

    if (k == 0) {
        cout << n << endl;
    } else {
        uint64_t t = 10, q;

        for (uint64_t i = 0; i != k - 1; ++i) {
            t *= 10;
        }

        q = t;

        for (uint64_t i = 2; i <= t / 2; ++i) {
            while (q % i == 0 && n % i == 0) {
                q /= i; n /= i;
            }
        }

        cout << n * t << endl;
    }
}
