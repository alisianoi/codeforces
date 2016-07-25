#include <iostream>
#include <algorithm>
#include <vector>

using vi = std::vector<int>;

int dfs(
    int node,
    int time,
    int mark,
    const std::vector<vi> &nodes,
    vi &times, vi &marks
) {
    time++;

    times[node] = time;
    marks[node] = mark;

    mark = mark == 1 ? 2 : 1;

    for (auto n : nodes[node]) {
        if (times[n] == 0) {
            if (dfs(n, time, mark, nodes, times, marks) == -1) {
                return -1;
            };
        } else {
            if ((times[node] - times[n]) % 2 == 0) {
                return -1;
            }
        }
    }

    return 0;
}



int main() {
    int n, m, src, dst;

    std::cin >> n >> m;

    auto nodes = std::vector<vi>(n + 1);
    auto times = std::vector<int>(n + 1, 0);
    auto marks = std::vector<int>(n + 1, 0);

    while (m--) {
        std::cin >> src >> dst;

        nodes[src].push_back(dst);
        nodes[dst].push_back(src);
    }

    int time = 0;
    for (auto i = 1; i < n + 1; ++i) {
        if (times[i] != 0) {continue;}

        if (dfs(i, time, 1, nodes, times, marks) == -1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    auto A = std::count(marks.begin(), marks.end(), 1);
    auto B = std::count(marks.begin(), marks.end(), 2);

    std::cout << A << std::endl;
    for (auto i = 1; i < n + 1; ++i) {
        if (marks[i] == 1) {std::cout << i << " ";}
    } std::cout << std::endl;

    std::cout << B << std::endl;
    for (auto i = 1; i < n + 1; ++i) {
        if (marks[i] == 2) {std::cout << i << " ";}
    } std::cout << std::endl;
}
