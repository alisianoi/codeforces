#include<bits/stdc++.h>

using namespace std;

int fly_from(const string& s, const int n, int a, int b) {
    int i = a - 1, j = a + 1;

    for (; i >= 0; --i) {
        if (s[i] != s[a]) break;
    }

    for (; j < n; ++j) {
        if (s[j] != s[a]) break;
    }

    if (i == -1) {
        return j - a;
    } else if (j == n) {
        return a - i;
    } else {
        return min(j - a, a - i);
    }
}

int main() {
    ios::sync_with_stdio(0);

    int n, a, b; cin >> n >> a >> b;
    a--; b--;
    string s; cin >> s;

    if (s[a] == s[b]) {
        cout << 0 << endl; return 0;
    }

    cout << 1 << endl;
}
