#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    double s, x1, x2; cin >> s >> x1 >> x2;
    double t1, t2; cin >> t1 >> t2;
    double p, d; cin >> p >> d;

    double time = abs(x1 - x2) * t2;

    double t = 0;

    while (t < time) {
        if (p <= x1 && x1 <= x2 && d == 1) {
            t += abs(p - x2) * t1;
            if (t < time) time = t;
        } else if (p >= x1 && x1 >= x2 && d == -1) {
            t += abs(p - x2) * t1;
            if (t < time) time = t;
        } else if (d == 1) {
            t += abs(p - s) * t1; p = s; d = -1;
        } else if (d == -1) {
            t += p * t1; p = 0; d = 1;
        }
    }

    cout << time << endl;
}
