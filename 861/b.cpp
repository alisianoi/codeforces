#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int>& xs, int size) {
    int i = 1, floor = 0;
    for (; i + size <= xs.size(); i += size) {
        ++floor;
        for (int j = i; j != i + size; ++j) {
            if (xs[j] != 0 && xs[j] != floor) {
                return false;
            }
        }
    }

    ++floor;
    for (int j = i; j != xs.size(); ++j) {
        if (xs[j] != 0 && xs[j] != floor) {
            return false;
        }
    }

    return true;
}

int main() {
    int n; int k; cin >> n >> k;

    auto xs = vector<int>(101, 0);

    for (int i = 0; i != k; ++i) {
        int k, f; cin >> k >> f; xs[k] = f;
    }

    if (n == 1) {
        cout << 1 << endl;

        return 0;
    }

    if (xs[n] != 0) {
        cout << xs[n] << endl;

        return 0;
    }

    int good = 0, val = 0;
    for (int size = 1; size != 101; ++size) {
        if (solve(xs, size) == true) {
            if (good == 0) {
                good = size;

                val = (n - 1) / size;
            } else {
                if (val != (n - 1) / size) {
                    cout << -1 << endl; return 0;
                }
            }
        }
    }

    if (good == 0) {
        cout << -1 << endl;
    } else {
        cout << val + 1 << endl;
    }
}
