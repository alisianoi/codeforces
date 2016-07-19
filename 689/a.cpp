#include <iostream>
#include <array>

int main() {
    int x; std::string s;
    std::cin >> x >> s;

    std::array<bool, 4> moves = {true, true, true, true};

    for (auto i = s.begin(); i != s.end(); ++i) {
        if (*i == '1' || *i == '4' || *i == '7' || *i == '0') {
            moves[0] = false;
        }

        if (*i == '3' || *i == '6' || *i == '9' || *i == '0') {
            moves[1] = false;
        }

        if (*i == '1' || *i == '2' || *i == '3') {
            moves[2] = false;
        }

        if (*i == '7' || *i == '0' || *i == '9') {
            moves[3] = false;
        }
    }

    for (auto move : moves) {
        if (move) {std::cout << "NO" << std::endl; return 0;}
    }

    std::cout << "YES" << std::endl;
}
