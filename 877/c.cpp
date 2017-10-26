#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 * 3 << endl;
        
        for (int i = 1; i != n + 1; i += 2) {
            cout << i << " ";
        }

        for (int i = 2; i != n + 2; i += 2) {
            cout << i << " ";
        }

        for (int i = 1; i != n + 1; i += 2) {
            cout << i << " ";
        }

        cout << endl;
    } else {
        cout << (n + 1) / 2 + n / 2 * 2 << endl;

        for (int i = 2; i != n + 1; i += 2) {
            cout << i << " ";
        }

        for (int i = 1; i != n + 2; i += 2) {
            cout << i << " ";
        }

        for (int i = 2; i != n + 1; i += 2) {
            cout << i << " ";
        }

        cout << endl;
    }
}
