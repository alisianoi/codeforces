#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> years = vector<int>();

    cin >> n;
    for (int i = 0; i != n; ++i) {
        int year; cin >> year; years.push_back(year);
    }

    sort(years.begin(), years.end());

    cout << *next(years.begin(), n / 2) << endl;
}
