#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s; cin >> n >> s;

    auto as = vector<int>(n, 0);
    auto bs = vector<int>(n, 0);

    auto avs = vector<int>(n, 0);
    auto bvs = vector<int>(n, 0);

    for (int i = 0; i != n; ++i) {
        cin >> as[i];
    }

    for (int i = 0; i != n; ++i) {
        cin >> bs[i];
    }

    if (as[0] == 0) {
        cout << "NO" << endl;

        return 0;
    }

    if (as[s - 1] == 1) {
        cout << "YES" << endl;

        return 0;
    }

    if (bs[s - 1] == 0) {
        cout << "NO" << endl;

        return 0;
    }

    for (int i = s; i != n; ++i) {
        if (as[i] == 1 && bs[i] == 1) {
            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;
}
