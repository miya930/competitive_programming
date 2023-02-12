#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    ll r, l;
    cin >> l >> r;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> dpl(n+1, vector<ll>(2, infl)), dpr(n+1, vector<ll>(2, infl));
    dpl[0][0] = 0; dpl[0][1] = 0;
    dpr[n][0] = 0; dpr[n][1] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dpl[i+1][1] = min(dpl[i+1][1], dpl[i][1] + l);
            dpl[i+1][0] = min(dpl[i+1][0], dpl[i][1] + a[i]);
            dpl[i+1][0] = min(dpl[i+1][0], dpl[i][0] + a[i]);
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            dpr[i][1] = min(dpr[i][1], dpr[i+1][1] + r);
            dpr[i][0] = min(dpr[i][0], dpr[i+1][1] + a[i]);
            dpr[i][0] = min(dpr[i][0], dpr[i+1][0] + a[i]);
        }
    }

    ll ans = infl;
    for (int i = 0; i <= n; i++) {
        ll ml = min(dpl[i][0], dpl[i][1]);
        ll mr = min(dpr[i][0], dpr[i][1]);

        ans = min(ans, ml+mr);
    }

    cout << ans << endl;
    return 0;
}
