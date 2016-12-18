#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;
    string s; cin >> s;

    string r; r = s[0];

    for (std::size_t i = 1; i < s.size(); ++i) {
        if (i % 2 == 0) {
            if (s.size() % 2)
                r = r + s[i];
            else
                r = s[i] + r;
        } else {
            if (s.size() % 2)
                r = s[i] + r;
            else
                r = r + s[i];
        }
    }

    cout << r << endl;
}
