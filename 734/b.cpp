#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>

int main() {
    std::uint64_t k2, k3, k5, k6; std::cin >> k2 >> k3 >> k5 >> k6;

    std::uint64_t k256 = std::min({k2, k5, k6});
    std::uint64_t k32 = std::min({k2 - k256, k3});

    std::cout << k32 * 32 + k256 * 256 << std::endl;;
}
