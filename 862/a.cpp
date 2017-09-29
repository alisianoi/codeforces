#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x; cin >> n >> x;
    auto ns = vector<int>(101, 0);

    for (int i = 0; i != n; ++i) {
        int tmp; cin >> tmp;
        ns[tmp] = 1;
    }

    int answer = 0;
    for (int i = 0; i <= x - 1; ++i) {
        if (ns[i] == 0) {
            ++answer;
        }
    }

    if (ns[x] == 1) {
        ++answer;
    }

    cout << answer << endl;
}
