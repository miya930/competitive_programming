#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1, 0);
    a[1] = 1; a[2] = 1;

    for (ll i = 3; i <= n; ++i) {
        a[i] = a[i-1] + a[i-2];
        a[i] %= mod;
    }

    cout << a[n] << endl;
    return 0;
}
