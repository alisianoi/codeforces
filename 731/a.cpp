#include <iostream>

int main() {
    std::string name;
    std::cin >> name;

    char letter = 'a';
    int rotations = 0;

    for (const auto& l: name) {
        const auto dst = std::abs(l - letter);
        rotations += dst <= 13 ? dst : 13 - dst % 13;
        letter = l;
    }

    std::cout << rotations << std::endl;
}
