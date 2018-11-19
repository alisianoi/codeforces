#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    const auto size = s.length();

    u32 rows = 6;
    u32 cols = 21;

    for (u32 i = 20; i != 1; --i) {
        const u32 j = (size + i - 1) / i;

        if (j > rows) {
            break;
        }

        if (j < rows || i < cols) {
            cols = i;
            rows = j;
        }
    }

    if (rows == 1) {

        cout << 1 << " " << size << endl;

        cout << s << endl;

        return 0;
    }

    u32 left = (rows * cols - size) / rows;
    u32 bons = (rows * cols - size) % rows;

    u32 c = 0;

    cout << rows << " " << cols << endl;;
    for (u32 i = 0; i != rows; ++i) {
        for (u32 j = 0; j != cols; ++j) {
            if (j < left) {
                cout << "*";
            } else if (j == left && i < bons) {
                cout << "*";
            } else {
                cout << s[c];

                ++c;
            }
        } cout << endl;
    }
}
