#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, m, a, b;

    cin >> n >> m >> a >> b;

    uint64_t r = n % m;

    uint64_t costa = (m - r) * a;
    uint64_t costb = r * b;

    if (costa < costb) {
        cout << costa << endl;
    } else {
        cout << costb << endl;
    }
}
