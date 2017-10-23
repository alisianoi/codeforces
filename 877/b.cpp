#include<bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;

    const auto N = s.size();
    uint32_t must_remove = 6000;

    auto as = vector<uint32_t>(N + 1, 0);
    auto bs = vector<uint32_t>(N + 1, 0);

    for (uint32_t i = 1; i != N + 1; ++i) {
        as[i] = as[i - 1];
        bs[i] = bs[i - 1];

        if (s[i - 1] == 'a') {
            as[i]++;
        } else {
            bs[i]++;
        }
    }

    for (uint32_t i = 0; i != N + 1; ++i) {
        const auto b0 = bs[i];

        for (uint32_t j = i; j != N + 1; ++j) {
            const auto a1 = as[j] - as[i];
            const auto b2 = bs[N] - bs[j];

            if (b0 + a1 + b2 < must_remove) {
                must_remove = b0 + a1 + b2;
            }
        }
    }

    cout << s.size() - must_remove << endl;
}
