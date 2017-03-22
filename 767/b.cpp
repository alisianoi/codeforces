#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t1, t2, t3, n, t, m = 1e12+7, ans;

    cin >> t1 >> t2 >> t3 >> n;

    while (n--) {
        cin >> t;

        if (t <= t2 - t3) {
            if (max(t1, t - 1) <= t2 - t3 && t1 - t + 1 < m)
                m = t1 - t + 1, ans = min(t1, t - 1);

            t1 = max(t1, t) + t3;
        }
    }

    if (t1 <= t2 - t3)
        ans = t1;

    cout << ans << endl;
}
