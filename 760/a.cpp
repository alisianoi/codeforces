#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    int limit = 1000;

    auto xs = vector<int>(limit * limit + 2, 0);

    for (int i = 2; i < limit * limit + 2; ++i) {
        if (xs[i] != 0) continue;

        for (int j = i; j < limit * limit + 2; j += i) {
            xs[j] = i;
        }
    }

    if (n % 2 == 1) { cout << 3 << endl; return 0;}

    for (int j = n + n; j < limit * limit + 2; j += n) {
        if (xs[j + 1] != j + 1) {
            cout << j / n << endl; return 0;
        }
    }
}
