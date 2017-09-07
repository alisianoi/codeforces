#include<bits/stdc++.h>

using namespace std;

int main() {
    uint64_t n, k; cin >> n >> k;

    auto queue = priority_queue<pair<uint64_t, uint64_t>>();
    auto answer = vector<int>(n, 0);

    uint64_t cost, index, total = 0;
    for (uint64_t i = 0; i != n + k; ++i) {
        if (i < n) {
            cin >> cost;
            queue.push({cost, i});
        }

        if (i >= k) {
            std::tie(cost, index) = queue.top(); queue.pop();
            total += cost * (i - index);
            answer[index] = i + 1;
        }
    }

    cout << total << endl;

    for (auto which: answer) {
        cout << which << " ";
    } cout << endl;
}
