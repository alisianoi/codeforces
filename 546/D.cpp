#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    const auto n = 5000000;
    auto primes = std::vector<int>(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (primes[i] == 0) {
            for (int j = i; j <= n; j += i) {
                primes[j] = i;
            }
        }
    }

    auto presum = std::vector<int>(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        primes[i] = primes[i / primes[i]] + 1;
        presum[i] = presum[i - 1] + primes[i];
    }

    int a, b, t;

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &a, &b);
        std::cout << presum[a] - presum[b] << '\n';
    }
}
