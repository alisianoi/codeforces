#include <iostream>

int main() {
    int n, d, cur = 0, max = 0;
    std::cin >> n >> d;

    while (d--) {
        std::string s;
        std::cin >> s;

        if (s.find('0') != std::string::npos) {
            cur++;
        } else {
            if (cur > max) {
                max = cur;
            }
            cur = 0;
        }
    }
    if (cur > max) {max = cur;}

    std::cout << max << std::endl;
}
