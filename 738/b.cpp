#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    std::vector<std::vector<int>> a, l, r, u, d;

    for (int i = 0; i < n; ++i) {
        a.push_back(vector<int>(m, 0));
        l.push_back(vector<int>(m, 0));
        r.push_back(vector<int>(m, 0));
        u.push_back(vector<int>(m, 0));
        d.push_back(vector<int>(m, 0));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    unsigned int total = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] == 1) continue;
            if (a[i][j - 1] == 1 || l[i][j - 1] == 1) {
                l[i][j] = 1; total++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j > -1; --j) {
            if (a[i][j] == 1) continue;
            if (a[i][j + 1] == 1 || r[i][j + 1] == 1) {
                r[i][j] = 1; total++;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (a[i][j] == 1) continue;
            if (a[i - 1][j] == 1 || u[i - 1][j] == 1) {
                u[i][j] = 1; total++;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = n - 2; i > -1; --i) {
            if (a[i][j] == 1) continue;
            if (a[i + 1][j] == 1 || d[i + 1][j] == 1) {
                d[i][j] = 1; total++;
            }
        }
    }

    std::cout << total << std::endl;
}
