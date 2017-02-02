#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, m, z; cin >> n >> m >> z; int total = 0;

    int i = n, j = m;

    while (i <= z && j <= z) {
        if (i == j) {
            total++;

            i += n;
            j += m;
        } else if (i < j) {
            i += n;
        } else {
            j += m;
        }
    }

    cout << total << endl;
}
