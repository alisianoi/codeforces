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

    int64_t n; cin >> n;

    auto bs = vector<int64_t>(n, 0);

    for (int64_t i = 0; i != n; ++i) {
        cin >> bs[i];
    }

    if (n == 1) {
        cout << 0 << endl;

        return 0;
    }

    int64_t r0 = (bs[n - 1] - bs[0]) / (n - 1); // -1; -1 or +0; +0 or +1; +1
    int64_t r1 = (bs[n - 1] - bs[0] + 1) / (n - 1); // +1; 0 or +0; -1
    int64_t r2 = (bs[n - 1] - bs[0] - 1) / (n - 1); // -1; 0 or +0; +1
    int64_t r3 = (bs[n - 1] - bs[0] - 2) / (n - 1); // -1; +1
    int64_t r4 = (bs[n - 1] - bs[0] + 2) / (n - 1); // +1; -1

    int64_t change = -1;

    if (bs[n - 1] + 0 == bs[0] + 0 + r0 * (n - 1)) {
        change = solve(bs, +0, r0);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] + 0 == bs[0] - 1 + r1 * (n - 1)) {
        change = solve(bs, -1, r1);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] + 1 == bs[0] + 0 + r1 * (n - 1)) {
        change = solve(bs, +0, r1);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] + 0 == bs[0] + 1 + r2 * (n - 1)) {
        change = solve(bs, +1, r2);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }    

    if (bs[n - 1] - 1 == bs[0] + 0 + r2 * (n - 1)) {
        change = solve(bs, +0, r2);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

        if (bs[n - 1] + 1 == bs[0] + 1 + r0 * (n - 1)) {
        change = solve(bs, +1, r0);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] - 1 == bs[0] - 1 + r0 * (n - 1)) {
        change = solve(bs, -1, r0);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] - 1 == bs[0] + 1 + r3 * (n - 1)) {
        change = solve(bs, +1, r3);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    if (bs[n - 1] + 1 == bs[0] - 1 + r4 * (n - 1)) {
        change = solve(bs, -1, r4);
    }

    if (change != -1) {
        cout << change << endl;

        return 0;
    }

    cout << -1 << endl;
}
