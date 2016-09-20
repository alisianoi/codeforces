#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    auto ls = std::set<char>(s.begin(), s.end());
    auto xs = std::vector<int>(s.size(), ls.size());

    for (auto l: ls) {
        int last = -1;

        for (auto c = s.begin(); c != s.end(); ++c) {
            int i = std::distance(s.begin(), c);

            if (l == *c) last = i;

            if (last == -1) {
                xs[i] = s.size() + 1;
            } else {
                xs[i] = std::max(xs[i], i - last + 1);
            }
        }
    }

    std::cout << *std::min_element(xs.begin(), xs.end()) << std::endl;
}
