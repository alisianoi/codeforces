#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t total = 0;
    size_t ql = 0, qr = 0;
    string s; cin >> s;

    qr = count(s.begin(), s.end(), 'Q');

    for (auto c: s) {
        if (c == 'Q') {
            ++ql; --qr;
        }

        if (c == 'A') {
            total += ql * qr;
        }
    }

    cout << total << endl;
}
