#include<bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;

    int root = sqrt(N);
    if (root * root == N) {
        cout << 4 * root << endl;
    } else {
        int lower = (int) root;

        int upper = lower + 1;

        int answer = 4 * lower;

        lower *= lower;
        upper *= upper;

        int middle = (upper - lower) / 2 + lower;

        if (N <= middle) {
            cout << answer + 2 << endl;
        } else {
            cout << answer + 4 << endl;
        }
    }
}
