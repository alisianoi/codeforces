#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; cin >> x;
    string s; cin >> s;

    uint32_t i = 1;

    for (; i != s.size(); ++i) {
        if (s[i - 1] > s[i]) {
            break;
        }
    }

    if (i == s.size()) {
        for (uint32_t j = 0; j != s.size() - 1; ++j) {
            cout << s[j];
        } cout << endl;
    } else {
        for (uint32_t j = 0; j != s.size(); ++j) {
            if (j == i - 1) {
                continue;
            }

            cout << s[j];
        } cout << endl;
    }
}
