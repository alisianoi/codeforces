#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int today = 0;
    for (int i = 0; i != n; ++i) {
        int s, d; cin >> s >> d;

        if (s > today) {
            today = s;
        } else {
            // we already had an appointment today
            ++today;

            const auto q = (today - s) / d;
            const auto r = (today - s) % d;

            today = s + q * d + (r == 0 ? 0 : d);
        }
    }

    cout << today << endl;
}
