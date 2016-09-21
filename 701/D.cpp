#include <iostream>
#include <iomanip>

int main() {
    int n, l, v1, v2, k;
    std::cin >> n >> l >> v1 >> v2 >> k;

    auto m = (n + k - 1) / k;

    auto m1 = m / (double) (v2 - v1);
    auto m2 = (m - 1) / (double) (v2 + v1);

    std::cout << std::setprecision(10) << l * (m1 + m2) / (1 + v1 * (m1 + m2)) << std::endl;
}
