#include <iostream>
#include <cstdint>

int64_t combos(int64_t n) {
    int64_t ans = 0;
    for (int64_t k = 2; k * k * k <= n; ++k) {
        ans += n / (k * k * k);
    }

    return ans;
}

int main() {
    int64_t m; std::cin >> m;

    int64_t lo = 0, hi = 8e15 + 9;

    while (lo < hi) {
        auto mid = lo + (hi - lo) / 2;

        auto ans = combos(mid);

        if (ans < m) {lo = mid + 1;}
        else {hi = mid;}
    }

    if (combos(lo) == m) {
        std::cout << lo << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }
}
