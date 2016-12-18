#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int a, b, c; cin >> a >> b >> c;

    int x = b / 2; int y = c / 4;

    int tota = std::min(a, std::min(x, y));

    cout << 7 * tota << endl;
}
