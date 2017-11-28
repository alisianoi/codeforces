#include<bits/stdc++.h>

using namespace std;

template<typename T>
T fpow1(T x, T n, T m) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        throw runtime_error("Cannot raise to negative power");
    }

    T y = 1;

    while (n > 1) {
        if (n % 2 == 0) {
            x = x * x % m;
        } else {
            y = x * y % m;
            x = x * x % m;
        }

        n = n / 2;
    }

    return x * y % m;
}

int main() {
    unsigned long long n, m; int k;

    const unsigned long long mod = 1'000'000'007ULL;

    cin >> n >> m >> k;

    if (k == -1 && (n % 2 ^ m % 2)) {
        cout << 0 << endl;

        return 0;
    }

    cout << fpow1(fpow1(2ULL, (n - 1), mod), m - 1, mod)  << endl;
}
