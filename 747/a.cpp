#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    int a = n; int b = n; int d = n;

    for (int i = 1; i < n / 2 + 1; ++i) {
        if (n % i == 0) {
            int cura = n / i, curb = i;

            if (cura > curb)
                swap(cura, curb);

            if (curb - cura < d) {
                d = curb - cura;
                a = cura; b = curb;
            }
        }
    }

    cout << a << " " << b << endl;
}
