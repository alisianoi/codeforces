#include <bits/stdc++.h>

using namespace std;

int main() {
    const size_t size = 14;
    vector<uint64_t> board(size, 0);

    for (size_t i = 0; i != size; ++i) {
        cin >> board[i];
    }

    uint64_t total = 0;
    for (size_t i = 0; i != size; ++i) {
        if (board[i] == 0) {
            continue;
        }

        vector<uint64_t> move = board;

        uint64_t q = move[i] / size;
        uint64_t r = move[i] % size;

        move[i] = 0;

        for (size_t j = 0; j != size; ++j) {
            move[j] += q;
        }

        size_t j = i + 1;

        while (r != 0) {
            if (j == size) {
                j = 0;
            }

            ++move[j]; ++j; --r;
        }

        uint64_t current = 0;
        for (size_t j = 0; j != size; ++j) {
            if (move[j] % 2 == 0) {
                current += move[j];
            }
        }

        if (current > total) {
            total = current;
        }
    }

    cout << total << endl;
}
