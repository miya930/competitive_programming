#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 62;

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    ll ini = 0;
    ll ans = infl;
    for (ll i = 0; i < n; ++i) {
        if (i > x) break;
        ini += a[i];
        ll sum = ini;

        if (ans - sum > (x-i)*b[i]) {
            ans = sum + (x-i)*b[i];
        }

        ini += b[i];
    }

    cout << ans << endl;
    return 0;
}
