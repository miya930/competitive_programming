#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n+100);
    vector<ll> sum(n+100, 0);
    for (int i = 0; i <= n; ++i) cin >> a[i];

    for (int i = n; i >= 0; --i) {
        sum[i] = sum[i+1] + a[i];
    }

    ll now = 1;
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += now;
        now -= a[i];
        if (now < 0) {
            cout << -1 << endl;
            return 0;
        }
        now = min(now*2LL, sum[i+1]);
    }
    cout << ans << endl;
    return 0;
}
