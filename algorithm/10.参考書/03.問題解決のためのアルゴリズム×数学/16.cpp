#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll n, ll m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i ) cin >> a[i];
    ll ans = 0;
    
    for (int i = 0; i < n; ++i) {
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;
    return 0;
}
