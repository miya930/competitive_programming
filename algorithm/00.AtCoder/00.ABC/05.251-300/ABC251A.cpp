#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    string ans = "";
    if (s.size() == 1) {
        for (int i = 0; i < 6; ++i) ans += s;
    } else if (s.size() == 2) {
        for (int i = 0; i < 3; ++i) ans += s;
    } else {
        for (int i = 0; i < 2; ++i) ans += s;
    }

    cout << ans << endl;
    return 0;
}
