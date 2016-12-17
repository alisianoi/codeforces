#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s;

    string::size_type l = string::npos;
    string::size_type r = string::npos;

    for (int i = 0; i < n; ++i) {
        cin >> s;

        string::size_type x = s.find_first_of("X");
        string::size_type y = s.find_last_of("X");

        if (x == string::npos) continue;

        if (l == string::npos) {
            l = x; r = y;
        } else if (l != x || r != y) {
            cout << "NO" << endl; return 0;
        } else if (s.substr(x, y - x).find('.') != string::npos) {
            cout << "NO" << endl; return 0;
        }
    }


    cout << "YES" << endl;
}
