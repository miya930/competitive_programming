/**
   created: 09.10.2021 19:42:28
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    for (int i = 0 ; i < n; ++i) cin >> x[i];

    vector<ll> pos(n+1, 0);
    for (int i = 1; i < n; ++i) pos[i] = (x[i]-x[i-1])*a;

    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        if (pos[i] > b) ans += b;
        else ans += pos[i];
    }

    cout << ans << endl;

    return 0;
}
