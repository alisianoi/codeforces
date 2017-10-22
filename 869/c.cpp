#include <bits/stdc++.h>

using namespace std;

vector<uint64_t> invs;
vector<uint64_t> facs;

template<typename T>
T xadd(T a, T b, const T modulus) {
    return (a + b) % modulus;
}

template<typename T>
T xmul(T a, T b, const T modulus) {
    return (a * b) % modulus;
}

template<typename T>
std::tuple<T, int64_t, int64_t> xgcf(T a, T b) {
    int64_t s1 = 1, s2 = 0;
    int64_t t1 = 0, t2 = 1;

    while (b != 0) {
        const auto q = a / b;
        const auto r = a % b;

        a = b;
        b = r;

        const auto x = s1;
        s1 = s2;
        s2 = x - q * s2;

        const auto y = t1;
        t1 = t2;
        t2 = y - q * t2;
    }

    return {a, s1, t1};
}

template<typename T>
T xdiv(T a, T b, T modulus) {
    return xmul(a, invs[b], modulus);
}

template<typename T>
T choose_n_k(const T n, const T k, const T modulus) {
    if (k > n) {
        return 0;
    }

    if (k == 0 || k == n) {
        return 1;
    }

    T result = 1;
    for (T i = 0; i != min(k, n - k); ++i) {
        result = xdiv(xmul(result, (n - i), modulus), (i + 1), modulus);
    }

    return result;
}

// Read: compute for two, meaning compute for two islands
template<typename T>
T compute_42(const T a, const T b, const T modulus) {
    T total = 0;
    for (T k = 0; k != min(a, b) + 1; ++k) {
        const auto x = xmul(
            xmul(
                  choose_n_k(a, k, modulus)
                , choose_n_k(b, k, modulus)
                , modulus
            )
            , facs[k]
            , modulus
        );

        total = xadd(total, x, modulus);
    }

    return total;
}

int main() {
    uint64_t a, b, c; cin >> a >> b >> c;

    const uint64_t modulus = 998'244'353;

    invs.push_back(0);
    facs.push_back(1);
    for (uint64_t i = 1; i != 5001; ++i) {
        auto inv = get<1>(xgcf(i, modulus));
        while (inv < 0) {
            inv += modulus;
        }

        invs.push_back(inv);
        facs.push_back(facs[i - 1] * i % modulus);
    }

    uint64_t total0 = compute_42(a, b, modulus);
    uint64_t total1 = compute_42(a, c, modulus);
    uint64_t total2 = compute_42(b, c, modulus);

    cout << xmul(xmul(total0, total1, modulus), total2, modulus) << endl;
}
