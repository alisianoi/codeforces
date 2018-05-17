#include<bits/stdc++.h>

using namespace std;


struct compare {
    bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
        if (lhs[0] < rhs[0]) {
            return true;
        }

        return false;    
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    auto ws = vector<vector<int>>(n);

    for (int i = 0; i != n; ++i) {
        int w; cin >> w;

        ws[i] = {w, i};
    }

    sort(
        ws.begin(), ws.end(), [](const auto &lhs, const auto &rhs) {
            if (lhs[0] < rhs[0]) {
                return true;
            }

            return false;            
        }
    );

    auto es = set<vector<int>, compare>();

    string ppl; cin >> ppl;

    int j = 0;
    for (int i = 0; i != 2 * n; ++i) {
        if (ppl[i] == '0') {
            cout << ws[j][1] + 1 << endl;

            es.insert(ws[j]);
            ++j;
        } else {
            const auto &result = *es.rbegin();

            cout << result[1] + 1 << endl;

            es.erase(std::prev(es.end()));
        }
    }
}
