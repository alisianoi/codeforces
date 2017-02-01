#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int a, b; cin >> a >> b;

    if (a == 0 && b == 0) {
        cout << "NO" << endl;
    } else {
        cout << (abs(a - b) <= 1 ? "YES" : "NO") << endl;
    }
}
