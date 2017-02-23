#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ns = vector<int>(n + 2, 0);

    for (int i = 2; i < n + 2; ++i) {
        if (ns[i] != 0) continue;

        ns[i] = 1;

        for (int j = 2 * i; j < n + 2; j += i) {
            ns[j] = 2;
        }
    }

    if (n >= 3) cout << 2 << endl;
    else cout << 1 << endl;

    for (int i = 2; i < n + 2; ++i) {
        cout << ns[i] << ' ';
    } cout << endl;
}
