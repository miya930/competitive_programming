#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    if (s.size() != 8) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        bool flg = true;
        if (i == 0 || i == (s.size() - 1)) {
            if (s[i] < 'A' || s[i] > 'Z') {
                flg = false;
            }
        } else if (i == 1) {
            if (s[i] < '1' || s[i] > '9') {
                flg = false;
            }

        } else {
            if (s[i] < '0' || s[i] > '9') {
                flg = false;
            }
        }

        if (!flg) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
