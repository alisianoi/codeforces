#include<bits/stdc++.h>

using namespace std;

int64_t solve(const vector<int64_t> &bs, int offset, int64_t d) {
    int64_t change = 0;

    auto val = bs[0] + offset + d;
    for (size_t i = 1; i != bs.size(); ++i, val += d) {
        const auto diff = bs[i] - val;

        if (diff < -1 || diff > 1) {
            return -1;
        }

        if (diff != 0) {
            ++change;
        }
    }

    return offset == 0 ? change : change + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, w; cin >> n >> w;

    int64_t l = w, h = 0;
    bool pchange = false, nchange = false;

    int64_t current = 0;

    for (int64_t i = 0; i != n; ++i) {
        int64_t a;
        cin >> a;

        if (a < 0) {
            nchange = true;
        }
        if (a > 0) {
            pchange = true;
        }

        current += a;

        if (current < l) {
            l = current;
        }
        if (current > h) {
            h = current;
        }
    }

    if (!pchange && !nchange) {
        h = l = 0;
    }

    if (!pchange) {
        h = 0;
    }

    if (!nchange) {
        l = 0;
    }

    int64_t diff = std::abs(h - l);

    if (diff > w) {
        cout << 0 << endl;
    } else {
        cout << w - diff + 1 << endl;
    }
}
