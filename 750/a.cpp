#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, k; cin >> n >> k;

    int time = 240 - k;

    int total = 0; int i = 1;

    while (total + 5 * i <= time && i <= n) {
        total += 5 * i; i++;
    }

    cout << i - 1 << endl;
}
