#include<bits/stdc++.h>

using namespace std;

void populate(string& s, char c, int n) {
    for (int i = 0; i < n; ++i)
        s[s.find_first_of("?")] = c;
}

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;
    string s; cin >> s;

    auto na = count(s.begin(), s.end(), 'A');
    auto nc = count(s.begin(), s.end(), 'C');
    auto ng = count(s.begin(), s.end(), 'G');
    auto nt = count(s.begin(), s.end(), 'T');
    auto nq = count(s.begin(), s.end(), '?');

    auto m = max(na, max(nc, (max(ng, nt))));

    auto da = m - na;
    auto dc = m - nc;
    auto dg = m - ng;
    auto dt = m - nt;

    if (nq < da + dc + dg + dt) {
        cout << "===" << endl;
    } else if ((nq - (da + dc + dg + dt)) % 4 != 0) {
        cout << "===" << endl;
    } else {
        populate(s, 'A', da);
        populate(s, 'C', dc);
        populate(s, 'G', dg);
        populate(s, 'T', dt);

        for (int i = 0; i < (nq - (da + dc + dg + dt)); i += 4) {
            populate(s, 'A', 1);
            populate(s, 'C', 1);
            populate(s, 'G', 1);
            populate(s, 'T', 1);
        }

        cout << s << endl;
    }
}
