#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m, k; cin >> n >> m >> k;

    cout << (k - 1) / 2 / m + 1 << " "
         << (k - 1) / 2 % m + 1 << " "
         << (k % 2 == 0 ? "R" : "L") << endl;
}
