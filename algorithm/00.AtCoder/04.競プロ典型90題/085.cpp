#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> enum_divisors(ll n) {
    vector<ll> res;

    for (ll i = 1; i*i <= n; ++i) {
        if (n%i != 0) continue;
        res.push_back(i);
        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll k; cin >> k;

    vector<ll> fac  = enum_divisors(k);

    ll ans = 0;
    for (int i = 0; i < (int)fac.size(); ++i) {
        if (fac[i] > 10100) continue;
        for (int j = i; j < (int)fac.size(); ++j) {
            ll ab = fac[i] * fac[j];
            if (k%ab != 0) continue;
            ll c = k / ab;
            if (c < fac[j]) continue; 

            ans++;
            //cout << "a = " << fac[i] << "  b = " << fac[j] << "  c = " << c << endl;
        } 
    } 
    cout << ans << endl;
}
