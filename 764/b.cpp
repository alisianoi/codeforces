#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto as = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

    for (int i = 0; i < n / 2; i += 2) {
        int tmp = as[i];
        as[i] = as[n - i - 1];
        as[n - i - 1] = tmp;
    }

    for (auto a: as) {
        cout << a << " ";
    } cout << endl;
}
