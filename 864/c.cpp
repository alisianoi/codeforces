#include<bits/stdc++.h>

using namespace std;

int main() {
    uint64_t i, a, b, f, k;

    cin >> a >> b >> f >> k;

    uint64_t cb = b;

    if (k == 1) {
        if (b >= a) {
            cout << 0 << endl;
        } else if (b >= f && b >= a - f) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }

        return 0;
    }

    if (k == 2) {
        if (b >= 2 * a) {
            cout << 0 << endl;
        } else if (b >= a + a - f || (b >= f && b >= (a + a - f))) {
            cout << 1 << endl;
        } else if (b >= f && b >= 2 * (a - f)) {
            cout << 2 << endl;
        } else {
            cout << - 1 << endl;
        }

        return 0;
    }

    const uint64_t x1 = 2 * (a - f);
    const uint64_t x2 = 2 * f;

    if (b < f || b < x1 || b < x2) {
        cout << -1 << endl;

        return 0;
    }

    cb -= f; uint64_t stops = 0;
    for (i = 0; i != k - 1; ++i) {
        if (i % 2 == 0) {
            if (cb < x1) {
                cb = b; ++stops;
            }

            cb -= x1;
        } else {
            if (cb < x2) {
                cb = b; ++stops;
            }

            cb -= x2;
        }
    }

    if (i % 2 == 0) {
        if (cb < a - f) {
            ++stops;
        }
    } else {
        if (cb < f) {
            ++stops;
        }
    }

    cout << stops << endl;
}
