#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n, q; cin >> n >> q;

    auto free = priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>>();

    for (int i = 0; i < n; ++i) free.push(i + 1);

    auto cmp = [](pair<uint64_t, uint64_t> l, pair<uint64_t, uint64_t> r) {
        uint64_t li, lw, ri, rw;

        tie(li, lw) = l; tie(ri, rw) = r;

        if (lw == rw)
            return li > ri;

        return lw > rw;
    };

    auto busy = priority_queue<
        pair<uint64_t, uint64_t>, vector<pair<uint64_t, uint64_t>>, decltype(cmp)
    > (cmp);

    for (int i = 0; i < q; ++i) {
        uint64_t t, k, d; cin >> t >> k >> d;

        while (busy.size() && busy.top().second <= t) {
            auto srv = busy.top(); busy.pop();

            free.push(srv.first);
        }

        if (free.size() < k) {
            cout << "-1" << endl;
        } else {
            uint64_t total = 0;

            for (uint64_t i = 0; i < k; ++i) {
                int next = free.top(); free.pop();

                total += next;

                busy.push(make_pair(next, t + d));
            }

            cout << total << endl;
        }
    }
}
