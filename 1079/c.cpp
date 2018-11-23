#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const auto wall = numeric_limits<u32>::max();

    u32 n; cin >> n;

    auto notes = vector<u32>(n, 0);

    for (auto &note : notes) {
        cin >> note;
    }

    auto fingers = vector<u32>(n, 0);
    auto choices = vector<array<u32, 5>>(n);

    for (u32 i = 0; i != 5; ++i) {
        choices[0][i] = 1;
    }

    for (u32 i = 1; i != n; ++i) {

        if (notes[i] == notes[i - 1]) {
            for (u32 j = 0; j != 5; ++j) {
                choices[i][j] = 1;
            }

            if (fingers[i - 1] != 0) {
                choices[i][fingers[i - 1] - 1] = 0;
            }
        } else if (notes[i] > notes[i - 1]) {
            u32 j = 0;

            for (; j != 5; ++j) {
                if (choices[i - 1][j]) {
                    break;
                }
            }

            if (j == 4) {
                cout << "-1" << endl;

                return 0;
            }

            if (j == 3) {
                fingers[i] = 5;
            }

            for (++j; j != 5; ++j) {
                choices[i][j] = 1;
            }
        } else {  // notes[i] < notes[i - 1]
            u32 j = 4;

            for (; j != wall; --j) {
                if (choices[i - 1][j]) {
                    break;
                }
            }

            if (j == 0) {
                cout << "-1" << endl;

                return 0;
            }

            if (j == 1) {
                fingers[i] = 1;
            }

            for (--j; j != wall; --j) {
                choices[i][j] = 1;
            }
        }
    }

    u32 f = 6;

    if (fingers[n - 1]) {
        f = fingers[n - 1];
    } else {
        for (u32 i = 0; i != 5; ++i) {
            if (choices[n - 1][i]) {
                f = i + 1;
            }
        }
    }

    fingers[n - 1] = f;

    for (u32 i = n - 2; i != wall; --i) {
        if (notes[i] == notes[i + 1]) {
            for (u32 j = 0; j != 5; ++j) {
                if (j + 1 != f && choices[i][j]) {
                    f = j + 1;

                    fingers[i] = f;

                    break;
                }
            }
        } else if (notes[i] > notes[i + 1]) {
            for (u32 j = f; j != 5; ++j) {
                if (choices[i][j]) {
                    f = j + 1;

                    fingers[i] = f;
                }
            }
        } else {
            for (u32 j = f - 2; j != wall; --j) {
                if (choices[i][j]) {
                    f = j + 1;

                    fingers[i] = f;
                }
            }
        }
    }

    for (auto finger : fingers) {
        cout << finger << " ";
    } cout << endl;
}
