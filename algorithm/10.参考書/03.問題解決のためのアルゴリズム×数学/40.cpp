#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n-1; ++i) cin >> a[i];

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        b[i]--;
    }

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n-1; ++i) sum[i+1] = sum[i] + a[i];

    ll ans = 0;
    for (int i = 0; i < m-1; ++i) {
        if (b[i+1] > b[i]) ans += abs(sum[b[i+1]]-sum[b[i]]);
        else ans += abs(sum[b[i]] - sum[b[i+1]]);
    }

    cout << ans << endl;
    return 0;
}
