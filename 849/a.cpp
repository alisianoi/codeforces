#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    auto as = vector<int>(n, 0);
    auto bs = vector<int>(n, 0);

    for (int i = 0; i != n; ++i) {
        cin >> as[i];
    }

    if (as[0] % 2 == 0 || as[n - 1] % 2 == 0) {
        cout << "NO" << endl; return 0;
    }

    if (n % 2 == 0) {
        cout << "NO" << endl; return 0;
    }

    cout << "YES" << endl;
}
