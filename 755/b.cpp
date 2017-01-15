#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m; cin >> n >> m;

    vector<string> xs; vector<string> ys; string s;

    for (int i = 0; i < n; ++i) {
        cin >> s; xs.push_back(s);
    }

    for (int i = 0; i < m; ++i) {
        cin >> s; ys.push_back(s);
    }

    sort(xs.begin(), xs.end()); sort(ys.begin(), ys.end());

    int i = 0, j = 0;

    int total = 0;

    while (i < n && j < m) {
        if (xs[i] == ys[j]) {
            total++; i++; j++;
        } else if (xs[i] < ys[j]) {
            i++;
        } else {
            j++;
        }
    }

    n -= total; m -= total;

    if (n == m) {
        if (total % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    } else if (n > m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
