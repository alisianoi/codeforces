#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ns = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> ns[i];
    }

    sort(ns.begin(), ns.end());

    if (n == 1 || n == 2) {cout << 0 << endl; return 0;}

    int i = 1, j = n - 2;

    while (i < n && ns[i] == ns[0]) ++i;

    while (j >= 0 && ns[j] == ns[n - 1]) --j;

    if (j < i) {cout << 0 << endl;}
    else {cout << j - i + 1 << endl;}
}
