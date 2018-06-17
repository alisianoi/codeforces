#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    auto as = vector<int>(n, 0);
    auto fs = vector<int>(m, 0);

    for (int i = 0; i != n; ++i) {
      cin >> as[i];
    }

    for (int i = 0; i != m; ++i) {
      cin >> fs[i];
    }

    for (int i = 0; i != n; ++i) {
      bool found = false;
      for(int j = 0; j != m; ++j) {
        if (as[i] == fs[j]) {
          found = true;
          break;
        }
      }
      if (!found) {
        as[i] = -1;
      }
    }

    for (int i = 0; i != n; ++i) {
      if (as[i] != -1) {
        cout << as[i] << " ";
      }
    } cout << endl;
}
