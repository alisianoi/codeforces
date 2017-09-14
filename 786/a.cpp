#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int  k1, k2;

    cin >> k1;
    auto s1 = vector<int>(k1, 0);
    for (int i = 0; i != k1; ++i) {
        cin >> s1[i];
    }

    cin >> k2;
    auto s2 = vector<int>(k2, 0);
    for (int i = 0; i != k2; ++i) {
        cin >> s2[i];
    }

    auto ks = vector<int>{k1, k2};
    auto ss = vector<vector<int>>{s1, s2};

    auto counts1 = vector<int>(n + 1, k1);
    auto counts2 = vector<int>(n + 1, k2);
    for (int i = 0; i != 2; ++i) {
        counts1[i] = 0;
        counts2[i] = 0;
    }

    auto counts = vector<vector<int>>{counts1, counts2};

    auto q1 = queue<int>();
    auto q2 = queue<int>();
    q1.push(1);
    q2.push(1);

    auto queues = vector<queue<int>>{q1, q2};

    while (!queues[0].empty() or !queues[1].empty()) {
        for (int i = 0; i != 2; ++i) {
            int j = 1 - i;

            auto epoch = queues[i].size();

            for (std::size_t k = 0; k != epoch; ++k) {
                auto node = queues[i].front(); queues[i].pop();

                for (auto s: ss[i]) {
                    auto next = node - s;

                    if (next <= 0) {
                        next += n;
                    }

                    if (counts[i][next] > 0) {
                        if (counts[j][node] == -1) {
                            // the other guy wins at node
                            --counts[i][next];

                            if (counts[i][next] == 0) {
                                queues[j].push(next);
                            }
                        } else {
                            // the other guy loses at node, counts[j][node] == 0
                            counts[i][next] = -1;

                            queues[j].push(next);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i != 2; ++i) {
        for (int j = 2; j != n + 1; ++j) {
            if (counts[i][j] == 0) {
                cout << "Lose" << " ";
            } else if (counts[i][j] == -1) {
                cout << "Win" << " ";
            } else {
                cout << "Loop" << " ";
            }
        } cout << endl;
    }
}
