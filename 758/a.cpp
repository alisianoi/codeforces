#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ns = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) cin >> ns[i];

    auto m = *max_element(ns.begin(), ns.end());

    int result = 0;

    for (int i = 0; i < n; ++i) {
        result += m - ns[i];
    }

    cout << result << endl;
}
