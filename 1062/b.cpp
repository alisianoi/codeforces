#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

std::map<uint32_t, uint32_t> compute_primes(uint32_t n) {
    auto primes = std::map<uint32_t, uint32_t>();

    if (n == 0) {
        return primes;
    }

    uint32_t c = 0;

    for (; n % 2 == 0; n /= 2, ++c);

    if (c) {
        primes[2] = c;
    }

    for (uint32_t f = 3; f * f <= n; f += 2) {
        c = 0;
        for (; n % f == 0; n /= f, ++c);

        if (c) {
            primes[f] = c;
        }
    }

    if (n != 1) {
        primes[n] = 1;
    }

    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n; cin >> n;

    u32 C = 0;
    u32 total = 1;
    auto counts = set<u32>();
    auto primes = compute_primes(n);

    for (const auto &prime : primes) {
        total *= prime.first;

        C = max(C, prime.second);

        counts.insert(prime.second);
    }

    u32 base = 0;
    u32 plus = 0;

    while (C & (C - 1)) {
        ++C;
    }

    for (auto c : counts) {
        if (c != C) {
            plus = 1;
        }
    }

    while (C > 1) {
        C /= 2;
        ++base;
    }

    cout << total << " " << base + plus << endl;
}
