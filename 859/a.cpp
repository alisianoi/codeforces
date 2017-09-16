#include<bits/stdc++.h>

using namespace std;

int main() {
    int k; cin >> k;
    auto xs = vector<int>(k, 0);
    for (int i = 0; i != k; ++i) {
        cin >> xs[i];
    }

    sort(xs.begin(), xs.end());

    int prev = 0; int total = 0;
    for (int i = 0; i != k; ++i) {
        total += xs[i] - prev - 1;
        prev = xs[i];
    }

    if (xs[k - 1] < 25) {
        total += 25 - xs[k - 1];
    }

    total -= (25 - k);

    cout << total << endl;
}
