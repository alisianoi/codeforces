#include<bits/stdc++.h>

using namespace std;

int solve(
    unsigned long long n,
    unsigned long long len,
    unsigned long long fst,
    unsigned long long lst)
{
    if (fst > lst) return 0;

    if (n == 1) {
        return 1;
    }

    const auto clen = len / 2 + 1;

    if (lst < clen) {
        return solve(n / 2, len / 2, fst, lst);
    }

    if (fst > clen) {
        return solve(n / 2, len / 2, fst - clen, lst - clen);
    }

    const auto lft = solve(n / 2, len / 2, fst, clen - 1);
    const auto rgt = solve(n / 2, len / 2, 1, lst - clen);

    if (n % 2) {
        return 1 + lft + rgt;
    } else {
        return lft + rgt;
    }

}

int main() {
    ios::sync_with_stdio(0);

    unsigned long long n, fst, lst; cin >> n >> fst >> lst;

    unsigned long long m = n, len = 1;

    if (n == 0) {
        cout << 0 << endl; return 0;
    }

    if (n == 1) {
        cout << 1 << endl; return 0;
    }

    while (m != 1) {
        len = 2 * len + 1; m /= 2;
    }

    cout << solve(n, len, fst, lst) << endl;
}
