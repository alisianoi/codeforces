#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ps = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> ps[i];
    }

    int bs = 0;

    int result = 0;

    for (int i = 0; i < n; ++i) {
        int n; cin >> n;
        if (n == 1) bs++;
    }

    if (bs % 2 == 0) result++;

    auto vs = vector<int>(n, 0);

    int loops = 0;
    for (int i = 0; i < n; ++i) {
        if (vs[i] != 0) continue;

        int marker = i + 1;

        while (vs[i] == 0) {
            vs[i] = marker;

            i = ps[i] - 1;
        }

        if (vs[i] == marker) loops++;
    }

    if (loops != 1) result += loops;

    cout << result << endl;
}
