#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

ll sum(ll f, ll n) {
    ll res = (f+f-n+1)*n/2;
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n+1, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.rbegin(), a.rend());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll diff = a[i] - a[i+1];
        ll cnt = 1LL * diff * (i + 1);
        if (cnt <= k) {
            k -= cnt;
            ans += sum(a[i], diff) * (i+1);
        } else {
            ll d = k / (i+1);
            ll mo = k % (i+1);
            ans += sum(a[i], d) * (i+1);
            ans += (a[i]-d) * mo;
            break;
        }
    }

    cout << ans << endl; 

}
