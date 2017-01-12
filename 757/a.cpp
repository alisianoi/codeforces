#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string s; cin >> s;

    int n1 = 0; int n2 = 0; int n3 = 0;
    int n4 = 0; int n5 = 0; int n6 = 0;
    int n7 = 0;

    for (auto c : s) {
        if (c == 'B') {
            n1++;
        } else if (c == 'u') {
            n2++;
        } else if (c == 'l') {
            n3++;
        } else if (c == 'b') {
            n4++;
        } else if (c == 'a') {
            n5++;
        } else if (c == 's') {
            n6++;
        } else if (c == 'r') {
            n7++;
        }
    }

    n2 /= 2; n5 /= 2;

    vector<int> ns = {n1, n2, n3, n4, n5, n6, n7};
    cout << *min_element(ns.begin(), ns.end()) << endl;
}
