#include<iostream>
#include<utility>
#include<vector>
#include<tuple>
#include<unordered_map>
#include<algorithm>

using namespace std;

string bishop_pos(int x, int y) {
    string pos = "";

    if (x < 0)
        pos += "l";
    else
        pos += "r";

    if (y < 0)
        pos += "d";
    else
        pos += "u";

    return pos;
}

int main() {
    int n; std::cin >> n;

    int x0, y0; std::cin >> x0 >> y0;

    auto pieces = vector<pair<string, pair<int, int>>>(n);

    for (int i = 0; i < n; ++i) {
        char c; int x, y; std::cin >> c >> x >> y;
        pieces[i] = std::make_pair(c, std::make_pair(x - x0, y - y0));
    }

    sort(
        pieces.begin(), pieces.end(),
        [](const auto l, const auto r) {
            int lx, ly, rx, ry;

            std::tie(lx, ly) = std::get<1>(l);
            std::tie(rx, ry) = std::get<1>(r);

            const std::size_t dl = std::abs(lx) + std::abs(ly);
            const std::size_t dr = std::abs(rx) + std::abs(ry);

            return dl < dr;
        }
    );

    unordered_map<string, int> blocks;

    for (auto piece: pieces) {
        string t; std::pair<int, int> q; int x, y;
        std::tie(t, q) = piece; std::tie(x, y) = q;

        if (t == "B") {
            if (std::abs(x) == std::abs(y)) {
                if (blocks[bishop_pos(x, y)] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            } else {
                if (x == 0) {
                    if (y < 0)
                        blocks["d"] = 1;
                    else
                        blocks["u"] = 1;
                } else if (y == 0) {
                    if (x < 0)
                        blocks["l"] = 1;
                    else
                        blocks["r"] = 1;
                }
            }
        } else if (t == "R") {
            if (x == 0) {
                if (y < 0 && blocks["d"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                } else if (y > 0 && blocks["u"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            } else if (y == 0) {
                if (x < 0 && blocks["l"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                } else if (x > 0 && blocks["r"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            } else {
                if (std::abs(x) == std::abs(y)) {
                    blocks[bishop_pos(x, y)] = 1;
                }
            }
        } else if (t == "Q") {
            if (x == 0) {
                if (y < 0 && blocks["d"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                } else if (y > 0 && blocks["u"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            } else if (y == 0) {
                if (x < 0 && blocks["l"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                } else if (x > 0 && blocks["r"] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            }  else if (std::abs(x) == std::abs(y)) {
                if (blocks[bishop_pos(x, y)] == 0) {
                    std::cout<< "YES" << std::endl; return 0;
                }
            }
        }
    }

    std::cout << "NO" << std::endl;
}
