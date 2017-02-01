#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    auto xs = vector<vector<string::size_type>>(n);

    string::size_type t;

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;

        string::size_type x = m, y = m, z = m;

        t = s.find_first_of("1234567890");

        if (t != string::npos) {
            if (t < x) x = t;
        }

        t = s.find_last_of("1234567890");

        if (t != string::npos) {
            if (m - t < x) x = m - t;
        }

        t = s.find_first_of("abcdefghijklmnopqrstuvwxyz");

        if (t != string::npos) {
            if (t < y) y = t;
        }

        t = s.find_last_of("abcdefghijklmnopqrstuvwxyz");

        if (t != string::npos) {
            if (m - t < y) y = m - t;
        }

        t = s.find_first_of("*#&");

        if (t != string::npos) {
            if (t < z) z = t;
        }

        t = s.find_last_of("*#&");

        if (t != string::npos) {
            if (m - t < z) z = m - t;
        }

        xs[i] = {x, y, z};
    }

    string::size_type q = 3 * m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            for (int k = 0; k < n; ++k) {
                if (i == k || j == k) continue;

                t = xs[i][0] + xs[j][1] + xs[k][2];

                if (t < q) q = t;
            }
        }
    }

    cout << q << endl;
}
