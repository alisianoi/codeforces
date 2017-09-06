#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    if (n % 2 == 0) {
        int x = n / 2 - 1, y = n / 2 + 1;
        while (x % 2 == 0) {
            x -= 1; y += 1;
        }
        if (x == y) {
            x -= 1; y += 1;
        }
        cout << x << " " << y << endl;
    } else {
        cout << n / 2 << " " << n / 2 + 1 << endl;
    }
}
