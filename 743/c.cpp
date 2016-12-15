#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;

    if (n > 2)
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    else if (n == 2)
        cout << 2 << " " << 3 << " " << 6 << endl;
    else
        cout << -1 << endl;
}
