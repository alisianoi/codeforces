#include <iostream>

int main() {
    long long x;
    int n, d, sad = 0;
    std::string s;
    std::cin >> n >> x;

    while (n--) {
        std::cin >> s >> d;

        if (s[0] == '+') {
            x += d;
        } else  if (s[0] == '-') {
            if (x >= d) {
                x -= d;
            } else {
                sad++;
            }
        } else {
            std::cerr << "u noob" << std::endl;
        }
    }

    std::cout << x << " " << sad;
}
