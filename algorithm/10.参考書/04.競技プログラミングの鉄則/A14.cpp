#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> d[i];

    map<ll,int> mp1, mp2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll sum1 = a[i]+b[j];
            ll sum2 = c[i]+d[j];
            mp1[sum1]++;
            mp2[sum2]++;
        }
    }

    ll ans = 0;
    for (auto x : mp1) {
        ll t1 = x.first;
        ll t2 = x.second * mp2[k-t1];
        ans += t2;
    }
    
    if (ans > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}
