#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int n; std::cin >> n;

    if (n == 0)
        cout << 1 << endl;
    else {
        const auto r = n % 4;
        if (r == 1)
            cout << 8 << endl;
        else if (r == 2)
            cout << 4 << endl;
        else if (r == 3)
            cout << 2 << endl;
        else
            cout << 6 << endl;
    }
}
