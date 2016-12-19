#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    uint64_t n, k, a, b; cin >> n >> k >> a >> b;

    string A = "G", B = "B";

    if (a < b) {
        swap(a, b); swap(A, B);
    }

    if (k * (b + 1) < a) {cout << "NO" << endl; return 0;}

    while (a + b != 0) {
        for (uint64_t i = 0; i < k && a > b; ++i, --a) {
            cout << A;
        }

        if (b != 0) {cout << B; --b;}
    }

    cout << endl;
}
