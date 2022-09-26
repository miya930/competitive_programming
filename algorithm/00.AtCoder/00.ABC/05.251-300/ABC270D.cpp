#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0;  i < k; ++i) cin >> a[i];

    vector<int> dp(n+1, 0);
    for (int i = 0; i < k; ++i) dp[a[i]] = a[i];

    for (int i = 1; i < n; ++i) { 
        for (int j = 0; j < k; ++j) {
            if (dp[i] == 0) continue;
            if (i+a[j] > n) continue;

            dp[i+a[j]] = max(a[j] + (i - dp[i]), dp[i+a[j]]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
