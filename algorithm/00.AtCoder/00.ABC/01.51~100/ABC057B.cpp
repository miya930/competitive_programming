#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < m; ++i) cin >> c[i] >> d[i];

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        ll tmp = infl;
        int idx = 0;
        for (int j = 0; j < m; ++j) {
            int dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (tmp > dist) {
                tmp = dist;
                idx = j;
            }
        }
        ans[i] = idx;
    }

    for (int i = 0; i < n; ++i) cout << ans[i]+1 << endl;
    return 0;
}
