#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;
    s.push_back('#');

    bool ng = false;
    for (int i = a; i < c; ++i) {
        if (s[i] == '#' && s[i+1] == '#') ng = true;
    }
    for (int i = b; i < d; ++i) {
        if (s[i] == '#' && s[i+1] == '#') ng = true;
    }

    bool three = false;
    for (int i = b-1; i < d; ++i) {
        if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') three = true;
    }

    if (c > d && three == false) ng = true;

    if (!ng) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
