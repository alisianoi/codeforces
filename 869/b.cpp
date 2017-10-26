#include<bits/stdc++.h>

using namespace std;

int main() {
    uint64_t a, b;
    cin >> a >> b;
    // 0 <= a <= b

    if (a == b) {
        cout << 1 << endl;

        return 0;
    } else if (b - a > 10) {
        cout << 0 << endl;

        return 0;
    }

    const int x = a % 10;
    const int y = b % 10;

    if (x >= y) {
        cout << 0 << endl;

        return 0;
    }

    int total = 1;
    for (int i = x + 1; i != y + 1; ++i) {
        total *= i;
    }

    cout << total % 10 << endl;
}
