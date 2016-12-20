#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto rs = queue<int>(), ds = queue<int>();

    for (int i = 0; i < n; ++i) {
        char c; cin >> c;

        if (c == 'R') {
            rs.push(i);
        } else {
            ds.push(i);
        }
    }

    while (rs.size() != 0 && ds.size() != 0) {
        int r = rs.front(), d = ds.front();

        rs.pop(); ds.pop();

        if (r < d) {
            rs.push(r + n);
        } else {
            ds.push(d + n);
        }
    }

    if (rs.size() == 0) {cout << "D" << endl;}
    else {cout << "R" << endl;}
}
