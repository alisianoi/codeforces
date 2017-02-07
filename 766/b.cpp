#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto as = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> as[i];
    }

    sort(as.begin(), as.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (as[i] + as[j] <= as[k]) {
                    break;
                } else {
                    cout << "YES" << endl; return 0;
                }
            }
        }
    }

    cout << "NO" << endl;
}
