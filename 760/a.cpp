#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int m, d; cin >> m >> d;

    unordered_map<int, int> month2days = {
        {1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
        {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };

    int days = month2days[m];

    int result = 1;

    days -= 8 - d;

    result += days / 7;

    if (days % 7 != 0) result++;

    cout << result << endl;
}
