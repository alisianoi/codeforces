#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

int main() {
    int n; std::cin >> n;

    auto ps = std::vector<int>(n, 0);
    for (auto& p: ps) std::cin >> p;

    std::cin.ignore(1, '\n');

    std::string s;
    for (const auto& p: ps) {
        std::getline(std::cin, s);

        const auto c = std::count_if(
            s.begin(), s.end(), [](const char c) -> bool {
                const std::string vowels = "aeiouy";
                return vowels.find(c) != std::string::npos;
            }
        );

        if (c != p) {
            std::cout << "NO" << std::endl; return 0;
        }
    }

    std::cout << "YES" << std::endl;
}
