#include <iostream>

int main() {
    int n, x, c; std::cin >> n;

    c = 0;

    if (n == 1) {
        std::cin >> x;

        if (x) {std::cout << "YES" << std::endl;}
        else {std::cout << "NO" << std::endl;}

        return EXIT_SUCCESS;
    } else {
        while (n--) {
            std::cin >> x;

            if (x == 0) c++;
        }
    }

    if (c == 1) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}
