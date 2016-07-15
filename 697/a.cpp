#include <iostream>

int main() {
    int t, s, q, x;

    std::cin >> t >> s >> x;

    // t, t + s, t + s + 1, t + 2s, t + 2s + 1, ...
    for (q = t; q <= x; q += s) {
        if (q == x) {std::cout << "YES" << std::endl; return 0;}
    }

    for (q = t + s + 1; q <= x; q += s) {
        if (q == x) {std::cout << "YES" << std::endl; return 0;}
    }

    std::cout << "NO" << std::endl;
}
