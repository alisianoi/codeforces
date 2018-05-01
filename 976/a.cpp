#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    size_t n;
    string s;

    cin >> n >> s;

    cout << s[0];

    if (s[0] == '0') {
        cout << endl;
        return 0;
    }

    s.erase(std::remove(s.begin(), s.end(), '1'), s.end());

    cout << s << endl;
}
