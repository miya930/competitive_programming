#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll n, ll m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

ll lcm(ll n, ll m) {
    return n / gcd(n, m) * m;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = a[0];
    for (int i = 1; i < n; ++i) {
        ans = lcm(ans, a[i]);
    }

    cout << ans << endl;
    return 0;
}
