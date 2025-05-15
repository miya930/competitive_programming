#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ll mi = a[i] - d;
        ll ma = a[i] + d;

        ll idx1 = lower_bound(b.begin(), b.end(), mi) - b.begin();
        ll idx2 = lower_bound(b.begin(), b.end(), ma) - b.begin();
        ll idx3 = idx1+1;
        ll idx4 = idx2-1;

        ll diff1 = abs(a[i] - b[idx1]);
        ll diff2 = abs(a[i] - b[idx2]);
        ll diff3 = abs(a[i] - b[idx3]);
        ll diff4 = abs(a[i] - b[idx4]);
        if (diff1 <= d) ans = max(ans, a[i] + b[idx1]);
        if (diff2 <= d) ans = max(ans, a[i] + b[idx2]);
        if (diff3 <= d && idx3 < n) ans = max(ans, a[i] + b[idx3]);
        if (diff4 <= d && idx4 >= 0) ans = max(ans, a[i] + b[idx4]);
    }
    cout << ans << endl;
    return 0;
}
