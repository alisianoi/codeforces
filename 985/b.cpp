#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    auto ns = vector<int>(n, 0);
    auto xs = vector<vector<int>>(n, vector<int>(m, 0));

    string s;
    for (int i = 0; i != n; ++i) {
        cin >> s;
        for (int j = 0; j != m; ++j) {
            if (s[j] == '1') {
                ++xs[i][j];
            }
        }
    }

    for (int j = 0; j != m; ++j) {
        int k = -1;
        for (int i = 0; i != n; ++i) {
            if (xs[i][j] == 1) {
                if (k == -1) {
                    if (ns[i] != 1) {
                        ns[i] = 1;
                        k = i;
                    } else {
                        k = -2;
                    }
                } else if (k != -2) {
                    ns[k] = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i != n; ++i) {
        if (ns[i] == 0) {
            cout << "YES" << endl;

            return 0;
        }
    }

    cout << "NO" << endl;
}
