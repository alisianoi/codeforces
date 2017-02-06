#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    cout << "YES" << endl;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        if (x2 < x1 && y2 > y1) {
            swap(x1, x2);
            swap(y1, y2);
        }

        cout << 2 * (abs(x1) % 2) + abs(y1) % 2 + 1 << endl;;
    }
}
