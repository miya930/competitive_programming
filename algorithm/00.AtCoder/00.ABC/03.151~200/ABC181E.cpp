#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL<<60;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> h(n), w(m);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) cin >> w[i];

    sort(h.begin(), h.end());

    ll ans = infl;
    vector<ll> sum1((n+1)/2), sum2((n+1)/2);
    for (int i = 0; i+1 < n; i+=2) sum1[i/2+1] = sum1[i/2] + h[i+1] - h[i];
    for (int i = n - 2; i > 0; i -=2) sum2[i/2] = sum2[i/2+1] + h[i+1] - h[i];

    for (int t : w) {
        int x = lower_bound(h.begin(), h.end(), t) - h.begin();
        if (x & 1) x ^= 1;
        ans = min(ans, sum1[x/2] + sum2[x/2] + abs(h[x]-t));
    }
    
    cout << ans << endl;
    return 0;
}
