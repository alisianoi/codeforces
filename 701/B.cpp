#include <iostream>
#include <set>

int main() {
    std::uint64_t n, m; std::cin >> n >> m;

    auto xs = std::set<int>();
    auto ys = std::set<int>();

    while (m--) {
        int x, y; std::cin >> x >> y;

        xs.insert(x); ys.insert(y);

        std::cout << (n - xs.size()) * (n - ys.size()) << " ";
    }
}
