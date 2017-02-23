#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string name1, name2;

    cin >> name1 >> name2;

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string kill, next; cin >> kill >> next;

        cout << name1 << " " << name2 << endl;

        if (name1 == kill) {name1 = next;}
        else {
            name2 = next;
        }
    }

    cout << name1 << " " << name2 << endl;
}
