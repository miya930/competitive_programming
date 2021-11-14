#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (ll a = 1; a*a*a <= n; ++a) {
        ll na = n/a;
        for (ll b = a; b*b <= na; ++b) {
            ans += (n/(a*b)-b+1);
        }
    }

    cout << ans << endl;

    return 0;
}
