#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n; std::cin >> n;

    using pii = std::pair<int, int>;
    auto xs = std::vector<pii>(n, std::make_pair(42, 42));

    for (auto i = 0; i < n; ++i) {
        int x; std::cin >> x;
        xs[i] = std::make_pair(x, i + 1);
    }

    std::sort(
        xs.begin(), xs.end(), [](const pii& l, const pii& r) {
            return l.first < r.first;
        }
    );

    for (auto i = 0; i < n / 2; ++i) {
        std::cout << xs[i].second << " " << xs[n - 1 - i].second << std::endl;
    }
}
