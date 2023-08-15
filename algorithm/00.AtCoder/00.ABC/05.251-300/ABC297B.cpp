#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    bool flg = true;
    bool even = false, odd = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            if (i%2 == 0) even = true;
            else odd = true;
        }
    }
    if (even != true || odd != true) flg = false;

    int x = -1, y = -1, z = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'K') z = i;
        else if (s[i] == 'R') {
            if (x == -1) {
                x = i;
            } else {
                y = i;
            }
        }
    }

    if (!(x < z && z < y)) flg =false;
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
