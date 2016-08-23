#include <vector>
#include <iostream>

int main() {
    int n; std::cin >> n;
    auto days = std::vector<int>(n, 0);

    for (auto i = 0; i < n; ++i) {
        std::cin >> days[i];
    }

    int total = 0;

    for (auto i = 0; i < n - 1; ++i) {
        if (days[i] == 1) {
            if (days[i + 1] == 1) {
                days[i + 1] = 0;
            } else if (days[i + 1] == 3) {
                days[i + 1] = 2;
            }
            ++total;
        }

        if (days[i] == 2) {
            if (days[i + 1] == 2) {
                days[i + 1] = 0;
            } else if (days[i + 1] == 3) {
                days[i + 1] = 1;
            }
            ++total;
        }

        if (days[i] == 3) {
            ++total;
        }
    }

    if (days[n - 1] == 1 || days[n - 1] == 2 || days[n - 1] == 3) {++total;}

    std::cout << n - total << std::endl;
}
