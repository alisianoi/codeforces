#include<bits/stdc++.h>

using namespace std;

using dline = array<double, 3>;
using icoords = array<int, 8>;
using xcoords = array<int, 10>;
using dsquare = array<dline, 4>;

dline standard_line(double x0, double y0, double x1, double y1) {
    // Compute A, B and C, the three line coefficients of the equation:
    // Ax + By + C == 0

    return {y0 - y1, x1 - x0, x0 * y1 - x1 * y0};
}

double compute_location(const dline &line, const double x, const double y) {
    return line[0] * x + line[1] * y + line[2];
}

dsquare make_square(const icoords &coords) {
    // Compute four lines that contain the sides of the square.
    // Each line is described by the three coefficients (A, B and C) from the
    // line equation Ax + By + C == 0

    auto line0 = standard_line(coords[0], coords[1], coords[2], coords[3]);
    auto line1 = standard_line(coords[2], coords[3], coords[4], coords[5]);
    auto line2 = standard_line(coords[4], coords[5], coords[6], coords[7]);
    auto line3 = standard_line(coords[6], coords[7], coords[0], coords[1]);

    return {line0, line1, line2, line3};
}

bool is_inside(const dsquare &square, const double x, const double y) {
    // cerr << "Trying " << x << " " << y << endl;

    auto sides = array<double, 4>();
    for (int i = 0; i != 4; ++i) {
        sides[i] = compute_location(square[i], x, y);

        // cerr << "Against " << square[i][0] << " " << square[i][1] << " " << square[i][2] << " equals " << sides[i] << endl;
    }


    if (sides[0] >= 0 && sides[1] >= 0 && sides[2] >= 0 && sides[3] >= 0) {
        return true;
    }

    if (sides[0] <= 0 && sides[1] <= 0 && sides[2] <= 0 && sides[3] <= 0) {
        return true;
    }

    return false;
}

bool check_intersection(const dsquare &square, const xcoords &coords) {
    auto inside0 = is_inside(square, coords[0], coords[1]);
    auto inside1 = is_inside(square, coords[2], coords[3]);
    auto inside2 = is_inside(square, coords[4], coords[5]);
    auto inside3 = is_inside(square, coords[6], coords[7]);
    auto inside4 = is_inside(square, coords[8], coords[9]);

    if (inside0 || inside1 || inside2 || inside3 || inside4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int N = 8;

    auto as = array<int, N>();
    auto bs = array<int, N>();

    for (int i = 0; i != N; ++i) {
        cin >> as[i];
    }

    for (int i = 0; i != N; ++i) {
        cin >> bs[i];
    }

    auto square0 = make_square(as);
    auto square1 = make_square(bs);

    if (check_intersection(square0, {bs[0], bs[1], bs[2], bs[3], bs[4], bs[5], bs[6], bs[7], (bs[0] + bs[2]) / 2, (bs[1] + bs[3]) / 2})) {
        cout << "YES" << endl;
    } else if (check_intersection(square1, {as[0], as[1], as[2], as[3], as[4], as[5], as[6], as[7], (as[0] + as[2]) / 2, (as[1] + as[3]) / 2})) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
