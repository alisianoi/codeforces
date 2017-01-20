#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string s; cin >> s;

    int kr = 0, kb = 0, ky = 0, kg = 0;


    for (int i = 0; i < 4; ++i) {
        int j = i; for (; j < s.size() && s[j] == '!'; j += 4);

        if (s[j] == 'R') {
            kr += j / 4;
        } else if (s[j] == 'B') {
            kb += j / 4;
        } else if (s[j] == 'Y') {
            ky += j / 4;
        } else if (s[j] == 'G') {
            kg += j / 4;
        }

        auto c = s[j];

        for (j = j + 4; j < s.size(); j += 4) {
            if (s[j] == '!') {
                if (c == 'R') {
                    kr += 1;
                } else if (c == 'B') {
                    kb += 1;
                } else if (c == 'Y') {
                    ky += 1;
                } else if (c == 'G') {
                    kg += 1;
                }
            }
        }
    }

    cout << kr << " " << kb << " " << ky << " " << kg << endl;
}
