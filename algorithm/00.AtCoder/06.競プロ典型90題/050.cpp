#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int n, l;
    cin >> n >> l;

    int ans = 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; ++i) {
        if (i > 0) dp[i] += dp[i-1];
        if (i - l >= 0) dp[i] += dp[i-l];
        dp[i] %= MOD;
    }
    cout << dp[n] << endl;

}

/* 2022.4.10 復習 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    int n, l;
    cin >> n >> l;
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (l+i <= n) {
            dp[l+i] += dp[i];
            dp[l+i] %= mod;
        }
        dp[i+1] += dp[i];
        dp[i+1] %= mod;
    }

    cout << dp[n] << endl;
    return 0;
}


