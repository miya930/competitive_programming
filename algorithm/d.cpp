#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n), arev;
    for (int i = 0; i < n; ++i) cin >> a[i];

    arev = a;
    reverse(arev.begin(), arev.end());

    vector<ll> sum(n+1, 0), revsum(n+1, 0), lsum(n+1, 0), rsum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + a[i];
        revsum[i+1] = revsum[i] + arev[i];
        lsum[i+1] = lsum[i] + l;
        rsum[i+1] = rsum[i] + r;
    }

    vector<ll> lmi(n+1), rmi(n+1);
    bool flg1 = true, flg2 = true;
    for (int i = 1; i < n; ++i) {
        if (flg1) {
            lmi[i] = min(lmin[i-1]+l, lmin[i-1]+a[i-1]);
        } else {

        }
        lmi[i] = min(sum[i+1], lsum[i+1]);
        rmi[i] = min(revsum[i+1], rsum[i+1]);
    }

    for (int i = 0; i < n; ++i) cout << lmi[i] << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << rmi[i] << " ";
    cout << endl;

    ll ans = infl;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, lmi[i]+rmi[n-i]);
    }

    cout << ans << endl;

    return 0;
}
