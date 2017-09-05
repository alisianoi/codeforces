#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k, t; cin >> n >> k >> t;

    if (t <= k && t <= n) {
        cout << t << endl;
    } else if (t <= n) {
        cout << k << endl;
    } else {
        cout << max(0, k - (t - n)) << endl;
    }
}
