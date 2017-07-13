#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    auto as = vector<vector<int>>();

    for (int i = 0; i != n; ++i) {
        int messages; cin >> messages;
        as.push_back({messages, i});
    }

    sort(as.begin() + 1, as.end(), greater<vector<int>>());

    int messages = as[0][0];
    for (int i = 1; i != n; ++i) {
        if (messages == 0) {
            cout << -1 << endl;

            return 0;
        }

       messages = messages + as[i][0] - 1;
    }

    cout << n - 1 << endl;

    int i = 0; int j = 1;
    while (j != n) {
        if (as[i][0] == 0) {
            ++i;
        }

        cout << as[i][1] + 1 << " " << as[j][1]+ 1 << endl;;
        as[i][0]--;
        j++;
    }
}
