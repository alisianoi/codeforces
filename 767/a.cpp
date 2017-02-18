#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;
    auto xs = vector<int>(n + 1, 0);

    int j = n;
    for (int i = 1; i <= n; ++i) {
        int s; cin >> s;

        xs[s] = s;

        while (xs[j] != 0) {
            cout << j << " "; j--;
        } cout << endl;
    }
}
