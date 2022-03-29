#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n ;++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
    dp[0][0] = a[0];
    dp[0][1] = b[0];

    for (int i = 0; i < n-1; ++i) {
        if (abs(a[i+1] - dp[i][0]) <= k && dp[i][0] != -1) dp[i+1][0] = a[i+1];
        if (abs(a[i+1] - dp[i][1]) <= k && dp[i][1] != -1) dp[i+1][0] = a[i+1];
        if (abs(b[i+1] - dp[i][1]) <= k && dp[i][1] != -1) dp[i+1][1] = b[i+1];
        if (abs(b[i+1] - dp[i][0]) <= k && dp[i][0] != -1) dp[i+1][1] = b[i+1];
    }

    if (dp[n-1][0] != -1 || dp[n-1][1] != -1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
