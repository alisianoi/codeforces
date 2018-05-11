#include <bits/stdc++.h>

using namespace std;

void generate(vector<uint64_t> &ls, uint64_t n) {
    if (n >= 1e10) {
        return;
    }

    ls.push_back(n);

    generate(ls, n * 10 + 4);
    generate(ls, n * 10 + 7);
}

int main() {
    auto ls = vector<uint64_t>();

    generate(ls, 0);

    std::sort(ls.begin(), ls.end());

    uint64_t l, r; cin >> l >> r;

    uint64_t total = 0;
    for (uint64_t x = l; x != r + 1;) {
        const uint64_t nxt = *std::lower_bound(ls.begin(), ls.end(), x);
        const uint64_t bnd = std::min(nxt + 1, r + 1);
        const uint64_t inc = nxt * (bnd - x);

        total += inc;

        x = bnd;
    }

    cout << total << endl;
}
