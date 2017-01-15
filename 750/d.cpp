#include<bits/stdc++.h>

using namespace std;

void fly(
    int x, int y, int d, int i, int n,
    vector<vector<vector<vector<int>>>>& xs,
    vector<vector<int>>&                 vs,
    const vector<int>&                   ts
) {
    xs[x][y][i][d] = 1;

    const vector<int> dx = {-1, -1, -1,  0, +1, +1, +1, 0};
    const vector<int> dy = {-1,  0, +1, +1, +1, 0, -1, -1};

    for (int t = 0; t < ts[i]; ++t) {
        vs[x][y] = 1;

        x += dx[d];
        y += dy[d];
    }

    x -= dx[d];
    y -= dy[d];

    if (i + 1 == n) return;

    int nd0 = (d + 1) % 8;
    int nx0 = x + dx[nd0];
    int ny0 = y + dy[nd0];

    int nd1 = (d + 7) % 8;
    int nx1 = x + dx[nd1];
    int ny1 = y + dy[nd1];

    if (xs[nx0][ny0][i + 1][nd0] == 0)
        fly(nx0, ny0, nd0, i + 1, n, xs, vs, ts);
    if (xs[nx1][ny1][i + 1][nd1] == 0)
        fly(nx1, ny1, nd1, i + 1, n, xs, vs, ts);
}

int main() {
    int n; cin >> n;

    auto ts = std::vector<int>(n);

    for (int i = 0; i < n; ++i) cin >> ts[i];

    int limit = 301; int rlimit = 30;

    auto vs = vector<vector<int>>(limit);
    auto xs = vector<vector<vector<vector<int>>>>(limit);

    for (int i = 0; i < limit; ++i) {
        xs[i] = vector<vector<vector<int>>>(limit);

        vs[i] = vector<int>(limit, 0);

        for (int j = 0; j < limit; ++j) {
            xs[i][j] = vector<vector<int>>(rlimit);

            for (int r = 0; r < rlimit; ++r) {
                xs[i][j][r] = vector<int>(8, 0);
            }
        }
    }

    fly(150, 150, 7, 0, n, xs, vs, ts);

    int result = 0;

    for (int i = 0; i < limit; ++i) {
        result += count(vs[i].begin(), vs[i].end(), 1);
    }

    cout << result << endl;
}
