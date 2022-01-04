#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k), b(k);
    for (int i = 0; i < k; ++i) cin >> a[i];

    ll sum = 0, ex = 0;
    for (int i = 0; i < k; ++i) {
        ll d = a[i]*m;
        ll b1 = d/n;
        ll b2 = (d+n-1)/n;
        ll diff1 = abs(b1*n - d);
        ll diff2 = abs(b2*n - d);
        if (diff1 < diff2) {
            b[i] = b1;
        } else {
            b[i] = b2;
        }
        sum += b[i];
        if (sum >= m) break;
    }

    ex = m - sum;

    while (ex > 0) {
        ll mi = infl;
        ll miidx = -1;
        for (int i = 0; i < n; ++i) {
            ll d = a[i]*m;
            ll diff = abs((b[i]+1)*n-d);
            if (mi > diff) {
                mi = diff;
                miidx = i;
            }
        }
        b[miidx]++;
        ex--;
    }    

    for (int i = 0; i < k; ++i) cout << b[i] << " ";
    cout << endl;
    return 0;
}
