#include<iostream>
#include<algorithm>

int main() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    auto anton = std::count_if(
        s.begin(), s.end(), [](const auto c) {return c == 'A';}
        );
    auto danik = std::count_if(
        s.begin(), s.end(), [](const auto c) {return c == 'D';}
        );

    if (anton > danik) {
        std::cout << "Anton" << std::endl;
    } else if (danik > anton) {
        std::cout << "Danik" << std::endl;
    } else {
        std::cout << "Friendship" << std::endl;
    }
}
