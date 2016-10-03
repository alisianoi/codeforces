#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // v -- bus, u -- ped
    int n, x, y; double w, v, u;
    std::cin >> n >> w >> v >> u;

    auto ts = std::vector<double>(n + 1);

    bool flag = true;

    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        ts[i] = x / v + (w - y) / u;

        if (!(y / u <= x / v)) {
            flag = false;
        }
    }

    ts[n] = w / u;

    std::cout << std::setprecision(10);
    if (flag) {
        std::cout << ts[n] << std::endl;
    } else {
        std::cout << *std::max_element(ts.begin(), ts.end()) << std::endl;
    }
}
