#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdint>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, k, s, t; cin >> n >> k >> s >> t;

    auto cvs = vector<pair<int, int>>(n);

    for (int i = 0; i < n; ++i) {
        int c, v; cin >> c >> v;
        cvs[i] = {c, v};
    }

    auto gs = vector<int>(k);
    for (int i = 0; i < k; ++i) {
        cin >> gs[i];
    }

    sort(cvs.begin(), cvs.end(), [](const auto l, const auto r) {
            int cl, vl, cr, vr;

            std::tie(cl, vl) = l; std::tie(cr, vr) = r;

            return vl == vr ? cl < cr : vl < vr;
    });

    gs.push_back(0);
    gs.push_back(s);

    sort(gs.begin(), gs.end());

    auto fst = cvs.begin(), lst = cvs.end() - 1;

    while (fst <= lst) {
        bool failed = false;
        int time = 0, cap = 0;

        auto mid = std::next(fst, std::distance(fst, lst) / 2);

        std::tie(std::ignore, cap) = *mid;

        for (std::size_t i = 1; i < gs.size(); ++i) {
            int dst = gs[i] - gs[i - 1];

            if (cap < dst) {
                failed = true;
                break;
            } else if (cap < 2 * dst) {
                time += 3 * dst - cap;
            } else {
                time += dst;
            }
        }

        if (!failed && time <= t) {
            lst = mid - 1;
        } else {
            fst = mid + 1;
        }
    }

    if (fst == cvs.end()) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << std::get<0>(
            *min_element(fst, cvs.end(), [](const auto l, const auto r) {
                return std::get<0>(l) < std::get<0>(r);
            })
       ) << std::endl;
    }
}
