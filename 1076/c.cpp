#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double d;
    uint32_t t;

    cin >> t;
    for (uint32_t i = 0; i != t; ++i) {
        cin >> d;

        if (d == 0) {
            cout << "Y 0 0" << endl;
        } else if (d < 4) {
            cout << "N" << endl;
        } else {
            const auto x = sqrt(pow(d, 2) - 4 * d);
            cout << std::setprecision(
                std::numeric_limits<long double>::digits10 + 1
            );
            cout << "Y" << " " << (d + x) / 2 << " " << (d - x) / 2 << endl;
        }
    }
}
