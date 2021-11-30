#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ll diff = a[i] + a[i+1] - x;
        if (diff < 0) continue;

        if (diff <= a[i+1]) {
            a[i+1] -= diff;
        } else {
            a[i+1] = 0;
        }
        ans += diff;
    }

    cout << ans << endl;
    return 0;
}
