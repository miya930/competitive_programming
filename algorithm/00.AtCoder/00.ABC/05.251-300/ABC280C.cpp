#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    int ans = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
            ans = i;
            break;
        }
    }

    if (ans == -1) ans = t.size() - 1;

    cout << ans + 1 << endl;
    return 0;
}
