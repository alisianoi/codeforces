#include<bits/stdc++.h>

using namespace std;


using i32 = int32_t;
using i64 = int64_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

template<class RandomIt>
i64 compute_balance(RandomIt fst, RandomIt lst) {
    i64 balance = 0;

    for (; fst != lst; ++fst) {
        if (*fst == '(') {
            ++balance;
        } else {
            --balance;
        }

        if (balance < 0) {
            return -1;
        }
    }

    return balance;
}

template<class RandomIt>
void mirror_string(RandomIt fst, RandomIt lst) {
    reverse(fst, lst);

    for (; fst != lst; ++fst) {
        if (*fst == '(') {
            *fst = ')';
        } else {
            *fst = '(';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ui64 n; cin >> n;

    i32 balance = 0;

    auto brackets = vector<string>(n);
    auto balances = vector<i64>(300'000);

    for (ui64 i = 0; i != n; ++i) {
        cin >> brackets[i];

        balance = compute_balance(brackets[i].begin(), brackets[i].end());

        if (balance < 0) {
            continue;
        }

        ++balances[balance];
    }

    i64 total = 0;

    for (ui64 i = 0; i != n; ++i) {
        mirror_string(brackets[i].begin(), brackets[i].end());

        balance = compute_balance(brackets[i].begin(), brackets[i].end());

        if (balance < 0) {
            continue;
        }

        total += balances[balance];
    }

    cout << total << endl;
}
