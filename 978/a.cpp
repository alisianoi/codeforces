#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    auto as = vector<int>(n, 0);
    auto bs = vector<int>(n, 0);
    auto cs = vector<int>(1001, 0);

    for (int i = 0; i != n; ++i) {
        cin >> as[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        if (cs[as[i]] == 0) {
            cs[as[i]] = 1;
            bs[i] = 1;
        }
    }

    cout << std::count(bs.begin(), bs.end(), 1) << endl;
    for (int i = 0; i != n; ++i) {
        if (bs[i] == 1) {
            cout << as[i] << " ";
        }
    } cout << endl;
}
