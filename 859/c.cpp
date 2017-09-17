#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    auto as = vector<int>(n, 0);
    auto dp = vector<vector<int>>(n, vector<int>(2, 0));

    for (int i = 0; i != n; ++i) {
        cin >> as[i];
    }

    dp[n - 1][0] = 0;
    dp[n - 1][1] = as[n - 1];

    for (int i = n - 2; i != -1; --i) {
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][1] = as[i] + min(dp[i + 1][0], dp[i + 1][1]);
    }

    cout << min(dp[0][0], dp[0][1]) << " " << max(dp[0][0], dp[0][1]) << endl;
}
