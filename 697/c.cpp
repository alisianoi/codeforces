#include <iostream>
#include <cstdint>
#include <map>

int main() {
    auto m = std::map<uint64_t, uint64_t>();

    uint64_t q, t, v, u, w;

    std::cin >> q;
    while (q--) {
        std::cin >> t >> v >> u;

        if (t == 1) {
            std::cin >> w;

            while (v != u) {
                if (u > v) {std::swap(u, v);}

                m[v] += w;
                v /= 2;
            }
        } else {
            uint64_t total = 0;
            while (v != u) {
                if (u > v) {std::swap(u, v);}

                total += m[v];
                v /= 2;
            }
            std::cout << total << '\n';
        }
    }
}
