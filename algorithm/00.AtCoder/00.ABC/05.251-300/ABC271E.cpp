#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL<<60;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(m), b(m);
    vector<ll> c(m);
    vector<int> e(k);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }

    for (int i = 0; i < k; i++) {
        cin >> e[i];
        e[i]--;
    }

    vector<ll> dp(200100, infl);
    dp[0] = 0;

    for (int i = 0; i < k; i++) {
        dp[b[e[i]]] = min(dp[b[e[i]]], dp[a[e[i]]] + c[e[i]]);
    }

    if (dp[n-1] < infl) cout << dp[n-1] << endl;
    else cout << -1 << endl;

    return 0;
}
