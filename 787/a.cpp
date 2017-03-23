#include<bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(0);

    unsigned long long a, b, c, d;

    cin >> a >> b >> c >> d;

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (b + i * a == d + j * c) {
                cout << b + i * a << endl;

                return 0;
            }
        }
    }

    cout << -1 << endl;
}
