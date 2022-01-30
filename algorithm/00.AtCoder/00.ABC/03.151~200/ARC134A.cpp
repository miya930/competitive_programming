#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll w, l;
    cin >> n >> l >> w;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    ll now = 0;
    int cnt = 0;
    while (cnt < n) {
        if (now < a[cnt]) {
            ans = ans + (a[cnt]-now + w - 1)/w;
        } 
        now = max(now, a[cnt] + w);
        cnt++;
    }
    if (now < l) ans = ans + (l-now+w-1)/w;

    cout << ans << endl;
    return 0;
}
