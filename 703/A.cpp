#include <iostream>

int main() {
    int mn = 0, cn = 0;

    int n, m, c; std::cin >> n;

    while (n--) {
        std::cin >> m >> c;

        if (m > c) mn++;
        else if (c > m) cn++;
    }

    if (mn > cn) {
        std::cout << "Mishka" << std::endl;
    } else if (cn > mn) {
        std::cout << "Chris" << std::endl;
    } else {
        std::cout << "Friendship is magic!^^" << std::endl;
    }
}
