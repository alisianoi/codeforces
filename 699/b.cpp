#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
    int n, m; std::cin >> n >> m;

    auto xs = std::vector<std::vector<char>>(n, std::vector<char>(m));
    auto ys = std::vector<int>(n, 0);
    auto zs = std::vector<int>(m, 0);

    int total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> xs[i][j];

            if (xs[i][j] == '*') {
                ++ys[i]; ++zs[j]; ++total;
            }
        }
    }

    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (xs[i][j] == '.' && ys[i] + zs[j] == total ||
                xs[i][j] == '*' && ys[i] + zs[j] - 1 == total) {
                std::cout << "YES" << std::endl;
                std::cout << i + 1 << " " << j + 1 << std::endl;
                return EXIT_SUCCESS;
            }
        }
    }
    std::cout << "NO" << std::endl;
}
