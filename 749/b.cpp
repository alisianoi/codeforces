#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya; cin >> xb >> yb; cin >> xc >> yc;

    cout << 3 << endl;

    cout << xb + xc - xa << " " << yb + yc - ya << endl;
    cout << xa + xc - xb << " " << ya + yc - yb << endl;
    cout << xa + xb - xc << " " << ya + yb - yc << endl;
}
