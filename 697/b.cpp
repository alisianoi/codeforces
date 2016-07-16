#include <iostream>
#include <iterator>
#include <cstring>

int main() {
    std::string s;
    std::cin >> s;

    auto x = s.find('.');
    auto y = s.find('e');

    auto a = s.substr(0, x);
    auto d = s.substr(x + 1, y - x - 1);
    auto b = std::stoul(s.substr(y + 1));

    a += d.substr(0, b);

    if (d.size() > b) {
        if (b != 0) {
            a += '.' + d.substr(b);
        } else if (d != "0") {
            a += '.' + d;
        }
    } else {
        a += std::string(b - d.size(), '0');
    }

    std::cout << a << std::endl;
}
