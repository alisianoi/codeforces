#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b > a) swap(a, b);

    while (b) {
        int r = a % b;
        a = b; b = r;
    }

    return a;
}

int dfs(int b, int n, int i, int l, vector<int>& ns, vector<int>& vs) {
    vs[n] = i;

    if (vs[ns[n]] == -1)
        return dfs(b, ns[n], i, l + 1, ns, vs);

    if (vs[ns[n]] == i && ns[n] == b)
        return l;

    return -1;
}

int main() {
    ios::sync_with_stdio(0);

    int n; cin >> n;

    auto ns = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ns[i]; --ns[i];
    }

    auto vs = vector<int>(n, -1);
    auto ls = set<int>();
    for (int i = 0; i < n; ++i) {
        if (vs[i] != -1) continue;

        auto l = dfs(i, i, i, 1, ns, vs);

        if (l == -1) {
            cout << -1 << endl;
            return 0;
        }

        if (l % 2)
            ls.insert(l);
        else
            ls.insert(l / 2);
    }

    if (ls.size() == 1) {
        cout << *ls.begin() << endl;
    } else {
        uint64_t x = *ls.begin(), y = *(next(ls.begin(), 1));

        uint64_t result = x * y / gcd(x, y);

        for (auto i = next(ls.begin(), 2); i != ls.end(); ++i) {
            result = *i * result / gcd(*i, result);
        }

        cout << result << endl;
    }
}
