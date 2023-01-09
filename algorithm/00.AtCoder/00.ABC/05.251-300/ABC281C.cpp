#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    t %= sum;

    ll ans_idx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (t - a[i] > 0) t -= a[i];
        else {
            ans_idx = i + 1;
            ans = t;
            break;
        }
    }
    
    cout << ans_idx << " " << ans << endl;

    return 0;
}
