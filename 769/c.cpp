#include<bits/stdc++.h>

using namespace std;

bool bad(int x, int y, int m, int n, vector<vector<char>> &maze) {
    return x == -1 || x == m || y == -1 || y == n || maze[y][x] == '*';
}

int main() {
    int n, m, k, x, y;

    cin >> n >> m >> k;

    if (k % 2) {
        cout << "IMPOSSIBLE" << endl;

        return 0;
    }

    auto maze = vector<vector<char>>(n, vector<char>(m, '.'));

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            cin >> maze[i][j];

            if (maze[i][j] == 'X') {
                x = j;
                y = i;
            }
        }
    }

    map<char, vector<int>> deltas = {
        {'D', { 0, +1}},
        {'L', {-1,  0}},
        {'R', {+1,  0}},
        {'U', { 0, -1}}
    };

    auto dsts = vector<vector<int>>(n, vector<int>(m, -1)); dsts[y][x] = 0;

    auto q = queue<pair<int, int>>(); q.push(make_pair(x, y));

    while (q.size() != 0) {
        int a, b; tie(a, b) = q.front(); q.pop();

        for (auto letter: {'D', 'L', 'R', 'U'}) {
            auto delta = deltas[letter];

            int dx = a + delta[0];
            int dy = b + delta[1];

            if (bad(dx, dy, m, n, maze)) {
                continue;
            }

            if (dsts[dy][dx] != -1) {
                continue;
            }

            dsts[dy][dx] = dsts[b][a] + 1;
            q.push(make_pair(dx, dy));
        }
    }

    // for (auto x: dsts) {
    //     for (auto y: x) {
    //         cout << setw(2) << y << " ";
    //     } cout << endl;
    // }

    int total = 0;
    for (auto letter: {'D', 'L', 'R', 'U'}) {
        auto delta = deltas[letter];

        int dx = x + delta[0];
        int dy = y + delta[1];

        if (bad(dx, dy, m, n, maze)) {
            continue;
        }

        total++;
    }

    if (total == 0) {
        cout << "IMPOSSIBLE" << endl; return 0;
    }

    string path0 = "";

    for (int i = 0; i != k; ++i) {
        for (auto letter: {'D', 'L', 'R', 'U'}) {
            auto delta = deltas[letter];

            int dx = x + delta[0];
            int dy = y + delta[1];

            if (bad(dx, dy, m, n, maze)) {
                continue;
            }

            if (i + dsts[dy][dx] > k) {
                continue;
            }

            path0 += letter;

            x = dx;
            y = dy;

            break;
        }
    }

    cout << path0 << endl;
}
