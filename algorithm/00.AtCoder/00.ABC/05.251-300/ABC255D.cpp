#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{  
    ll n, Q;
    cin >> n >> Q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + a[i];
    }  

    for (ll q = 0; q < Q; ++q) {
        ll x;
        cin >> x;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        int idx2 = upper_bound(a.begin(), a.end(), x) - a.begin(); 
        
        ll ans;
        if (idx == n) {
            ans = x*n - sum[idx];
//            cout << "a"; 
        } else if (idx < n && idx2 == n) {
            ans = (x*idx - sum[idx]);
//            cout << "b";
        } else if (idx < n && idx2 < n) {
            ans = (x*idx - sum[idx]) + ((sum[n] - sum[idx2])-x*(n-idx2));
//            cout << "c";
        } else if (idx2 == 0) {
            ans = sum[n] - x*n;
 //           cout << "d";
        }
    
        cout << ans << endl;
    }

    return 0;
}
