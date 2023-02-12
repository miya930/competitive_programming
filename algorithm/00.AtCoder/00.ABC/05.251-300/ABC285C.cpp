#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    ll ans = 0;
    ll cur = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += (s[i] - 'A' + 1) * cur;
        cur *= 26;
    }

    cout << ans << endl;
    return 0;
}
