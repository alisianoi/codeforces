#include<bits/stdc++.h>

using namespace std;

template<typename T>
T fpow1(T x, T n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        throw std::runtime_error("Cannot raise to negative power");
    }

    T y = 1;

    while (n > 1) {
        if (n % 2 == 0) {
            x = x * x;
        } else {
            y = x * y;
            x = x * x;
        }

        n = n / 2;
    }

    return x * y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double x, y; cin >> x >> y;

    auto xy = y * log(x);
    auto yx = x * log(y);

    if (xy < yx) {
        cout << '<' << endl;
    } else if (xy > yx) {
        cout << '>' << endl;
    } else {
        cout << '=' << endl;
    }
}
