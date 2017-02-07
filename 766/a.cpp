#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string a, b; cin >> a >> b;

    if (a == b) {
        cout << -1 << endl;
    } else {
        cout << max(a.size(), b.size()) << endl;
    }
}
