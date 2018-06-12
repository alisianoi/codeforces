#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, K; cin >> n >> K;

    auto as = vector<uint64_t>(n, 0);

    for (size_t i = 0; i != n; ++i) {
        cin >> as[i];
    }

    std::sort(as.begin(), as.end(), std::greater<uint64_t>());

    size_t i = 0;
    size_t N = n;
    for (size_t j = 1; j != n; ++j) {
        if (as[j] < as[i] && as[i] <= as[j] + K) {
            --N;
        } else {
            if (i + 1 != j) {
                --j;
            }

            i = j;
        }
    }

    cout << N << endl;
}
