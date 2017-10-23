#include<bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;

    int total = 0;
    total += count(s.begin(), s.end(), "Danil");
    total += count(s.begin(), s.end(), "Olya");
    total += count(s.begin(), s.end(), "Slava");
    total += count(s.begin(), s.end(), "Ann");
    total += count(s.begin(), s.end(), "Nikita");

    if (total != 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
