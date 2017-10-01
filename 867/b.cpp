#include<bits/stdc++.h>

using namespace std;

int main() {
    int A; cin >> A;

    ios_base::sync_with_stdio(false);

    if (A == 1) {
        cout << 1 << " " << 1 << endl << 1 << endl;

        return 0;
    }

    cout << 2 * (A - 1) << " " << 2 << endl;
    cout << 1 << " " << 2 << endl;
}
