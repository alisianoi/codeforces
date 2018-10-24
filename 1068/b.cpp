#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::uint64_t n; cin >> n;

    if (n == 1) {
        cout << 1 << endl;

        return 0;
    }

    std::uint64_t total = 0;

    for (std::uint64_t i = 1; i < floor(sqrt(n)) + 1; ++i) {
        if (n % i == 0) {
            if (n / i != i) {
                total += 2;
            } else {
                total += 1;
            }
        }
    }
    cout << total << endl;
}
