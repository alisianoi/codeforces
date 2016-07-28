#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n; std::cin >> n;

    auto as = std::vector<int>(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> as[i];
    }

    for (auto fst = as.begin(); fst != as.end(); ++fst) {
        auto it = std::min_element(fst, as.end());

        for (auto i = std::distance(fst, it); i != 0; --i) {
            auto j = std::distance(as.begin(), fst);
            std::cout << i + j << " " << i + j + 1 << std::endl;
            std::swap(as[i + j - 1], as[i + j]);
        }
    }
}
