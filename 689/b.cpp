#include <iostream>
#include <cstdio>
#include <limits>
#include <vector>
#include <queue>

using vi = std::vector<int>;

int n;
vi xs;
vi cs;

int main() {
    std::cin >> n;

    xs.resize(n);
    cs.resize(n, std::numeric_limits<int>::max());

    for (auto i = 0; i < n; ++i) {
        scanf("%d", &xs[i]);
    }

    cs[0] = 0;
    std::queue<int> q({0});

    while (!q.empty()) {
        int x = q.front(); q.pop();
        int c = cs[x];

        if (x + 1 < n && c + 1 < cs[x + 1]) {
            cs[x + 1] = c + 1;
            q.push(x + 1);
        }

        if (x - 1 >= 0 && c + 1 < cs[x - 1]) {
            cs[x - 1] = c + 1;
            q.push(x - 1);
        }

        if (c + 1 < cs[xs[x] - 1]) {
            cs[xs[x] - 1] = c + 1;
            q.push(xs[x] - 1);
        }
    }

    for (auto i = 0; i < n; ++i) {
        printf("%d ", cs[i]);
    } std::cout << std::endl;
}
