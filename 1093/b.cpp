#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    i32 t; cin >> t;

    for (i32 i = 0; i != t; ++i) {
        string s; cin >> s;

        u32 j = 1;
        while (j != s.size()) {
            if (s[0] != s[j]) {
                break;
            }

            ++j;
        }

        if (j == s.size()) {
            cout << -1 << endl;
        } else {
            std::swap(s[j], s[s.size() - 1]);

            cout << s << endl;
        }
    }
}
