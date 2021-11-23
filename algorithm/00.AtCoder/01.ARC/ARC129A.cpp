#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;

    ll ans = 0;
    for (ll i = 0; i < 64; ++i) {
        if ((n>>i) & 1) {
            ll a = min(r,(1LL<<(i+1))-1);
            ll b = max(l,(1LL<<i));

            if (b <= a) ans += (a-b+1); 
        }
    }
    cout << ans << endl;

    return 0;
}
