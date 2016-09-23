#include <iostream>
#include <numeric>
#include <vector>

int main() {
    using ull = unsigned long long;

    int n, k, x; std::cin >> n >> k;

    auto ns = std::vector<ull>(n, 0);
    auto ks = std::vector<ull>(n, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> ns[i];
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> x;
        ks[x - 1] = 1;
    }

    ull result = 0;
    auto total = std::accumulate(ns.begin(), ns.end(), (ull) 0);

    for (int i = 0; i < n - 1; ++i) {
        if (ks[i] == 1) {
            result += ns[i] * (total - ns[i]);
            total -= ns[i];
        } else if (ks[i + 1] == 0) {
            result += ns[i] * ns[i + 1];
        }
    }

    if (ks[n - 1] == 1) {
        result += ns[n - 1] * (total - ns[n - 1]);
    } else if (ks[0] == 0){
        result += ns[n - 1] * ns[0];
    }

    std::cout << result << std::endl;
}
