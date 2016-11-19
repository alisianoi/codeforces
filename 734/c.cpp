#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#include <iterator>

using namespace std;

int main() {
    std::uint64_t n, m, k; std::cin >> n >> m >> k;

    std::uint64_t x, s; std::cin >> x >> s;

    auto ts1 = std::vector<std::uint64_t>(m, 0);
    auto cs1 = std::vector<std::uint64_t>(m, 0);
    for (std::uint64_t i = 0; i < m; ++i) {
        std::cin >> ts1[i];
    }

    for (std::uint64_t i = 0; i < m; ++i) {
        std::cin >> cs1[i];
    }

    auto ts2 = std::vector<std::uint64_t>(k, 0);
    auto cs2 = std::vector<std::uint64_t>(k, 0);
    for (std::uint64_t i = 0; i < k; ++i) {
        std::cin >> ts2[i];
    }

    for (std::uint64_t i = 0; i < k; ++i) {
        std::cin >> cs2[i];
    }

    std::uint64_t time;

    auto c2 = std::upper_bound(cs2.begin(), cs2.end(), s);
    if (c2 == cs2.begin()) {
        time = n * x;
    } else {
        auto n2 = *std::next(
            ts2.begin(), std::distance(cs2.begin(), c2) - 1
        );

        if (n > n2)
            time = (n - n2) * x;
        else
            time = 0;
    }

    for (std::uint64_t i = 0; i < m; ++i) {
        if (cs1[i] > s) continue;

        c2 = std::upper_bound(cs2.begin(), cs2.end(), s - cs1[i]);

        std::uint64_t ctime = 0;

        if (c2 == cs2.begin()) {
            ctime = n * ts1[i];
        } else {
            auto n2 = *std::next(
                ts2.begin(), std::distance(cs2.begin(), c2) - 1
            );

            if (n > n2)
                ctime = (n - n2) * ts1[i];
            else
                ctime = 0;
        }

        if (ctime < time)
            time = ctime;
    }

    std::cout << time << std::endl;
}
