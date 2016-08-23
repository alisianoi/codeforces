#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n; std::cin >> n;
    std::string where; std::cin >> where;
    auto ns = std::vector<int>(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> ns[i];
    }

    int ans = std::numeric_limits<int>::max();

    int i = 0, j = 1;
    while (j < n) {
        if (where[i] == 'R') {
            if (where[j] == 'L') {
                auto cur = (ns[j] - ns[i]) / 2;
                if (cur < ans) {ans = cur;}
            }
            i = j; j += 1;
        } else {
            i += 1;
            if (j <= i) {
                j = i + 1;
            }
        }
    }

    if (ans == std::numeric_limits<int>::max()) {
        std::cout << "-1" << std::endl;
    } else {
        std::cout << ans << std::endl;
    }
}
