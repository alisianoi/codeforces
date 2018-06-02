#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    auto ss = vector<string>(n);
    for (int i = 0; i != n; ++i) {
        cin >> ss[i];
    }

    sort(ss.begin(), ss.end(), [](const auto &lft, const auto &rgt) {
                                   if (lft.size() == rgt.size()) {
                                       return lft < rgt;
                                   }

                                   if (lft.size() < rgt.size()) {
                                       return true;
                                   }

                                   return false;
                               });

    int j = 0; bool ok = true;
    for (int i = 1; i != ss.size(); ++i, ++j) {
        if (ss[i].find(ss[j]) == std::string::npos) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "YES" << endl;

        for (auto s: ss) {
            cout << s << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
