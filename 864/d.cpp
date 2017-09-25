#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n; int total = 0;

    auto ns = vector<int>(n + 1, 0);
    auto cs = vector<int>(n + 1, 0);
    auto bs = vector<int>(n + 1, 0);

    for (int i = 1; i != n + 1; ++i) {
        cin >> ns[i]; ++cs[ns[i]];
    }

    int zi = 1;
    for (; zi != n + 1 && cs[zi] != 0; ++zi);

    for (int i = 1; i != n + 1; ++i) {
        if (cs[ns[i]] > 1) {
            if (zi < ns[i]) {
                ++total; --cs[ns[i]]; ++cs[zi];
                ns[i] = zi;
            } else {
                if (bs[ns[i]] == 0) {
                    bs[ns[i]] = 1;
                } else {
                    ++total; --cs[ns[i]]; ++cs[zi];
                    ns[i] = zi;
                }
            }

            for (; zi != n + 1 && cs[zi] != 0; ++zi);
        }
    }

    cout << total << endl;
    for (int i = 1; i != n + 1; ++i) {
        cout << ns[i] << " ";
    } cout << endl;
}
