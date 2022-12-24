#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n-1; ++i) cin >> a[i];
    for (int i = 0; i < n-2; ++i) cin >> b[i];

    vector<int> dp(n+1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (i < n-1) dp[i+1] = min(dp[i+1], dp[i]+a[i]);
        if (i < n-2) dp[i+2] = min(dp[i+2], dp[i]+b[i]);
    }

    cout << dp[n-1] << endl;

    return 0;
}
