#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    string s; cin >> s;

    int i = 0, j = 1, total = 0;
    for (int k = 2; k != n; ++k) {
        if (s[i] == s[j] && s[j] == s[k] && s[k] == 'x') {
            ++total;
            ++j;
        } else {
            i = j; ++j;
        }
    }

    cout << total << endl;
}
