#include<bits/stdc++.h>

using namespace std;

uint64_t dst2(int64_t ax, int64_t ay, int64_t bx, int64_t by) {
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

bool is_triangle(int64_t ax, int64_t ay, int64_t bx, int64_t by, int64_t cx, int64_t cy) {
    auto side0 = sqrt((long double) dst2(ax, ay, bx, by));
    auto side1 = sqrt((long double) dst2(ax, ay, cx, cy));
    auto side2 = sqrt((long double) dst2(bx, by, cx, cy));

    if (side0 + side1 <= side2) {
        return false;
    }

    if (side0 + side2 <= side1) {
        return false;
    }

    if (side1 + side2 <= side0) {
        return false;
    }

    return true;
}

int main() {
    int64_t ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if (ax == cx && ay == cy) {
        cout << "YES" << endl; return 0;
    }

    if (dst2(ax, ay, bx, by) == dst2(bx, by, cx, cy)) {
        if (is_triangle(ax, ay, bx, by, cx, cy)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }
}
