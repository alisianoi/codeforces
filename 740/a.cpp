#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    std::uint64_t n, a, b, c; cin >> n >> a >> b >> c;

    std::uint64_t r = n % 4;

    if (r == 0) {
        std::cout << 0 << std::endl;
    } else if (r == 1) {
        std::uint64_t x = 3 * a;
        std::uint64_t y = a + b;
        std::uint64_t z = c;

        std::cout << min({x, y, z}) << std::endl;
    } else if (r == 2) {
        std::uint64_t x = 2 * a;
        std::uint64_t y = b;
        std::uint64_t z = 2 * c;

        std::cout << min({x, y, z}) << std::endl;
    } else if (r == 3) {
        std::uint64_t x = a;
        std::uint64_t y = b + c;
        std::uint64_t z = 3 * c;

        std::cout << min({x, y, z}) << std::endl;
    }
}
