#include<iostream>

using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;

    for (unsigned int i = 0; i + 2 < s.size(); ++i) {
        if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {

            unsigned int j = i + 3;
            for (; j + 1 < s.size(); j += 2) {
                if (s[j] != 'g' || s[j + 1] != 'o') break;
            }

            s.replace(i, j - i, "***");
        }
    }

    std::cout << s << std::endl;
}
