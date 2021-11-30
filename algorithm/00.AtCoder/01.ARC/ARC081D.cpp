#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; ++i) cin >> s[i];

    ll right = 0;
    ll ans = 1;
    ll pre = -1;
    while (right < n) {
        if (s[0][right] == s[1][right]) {
            if (pre < 0) ans = 3;
            else if (pre == 0) ans *= 2;
            else ans *= 1;
            right++;
            pre = 0;
        } else {
            if (pre < 0) ans = 6;
            else if (pre == 0) ans *= 2;
            else ans *= 3;
            right += 2;
            pre = 1;
        }
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}
