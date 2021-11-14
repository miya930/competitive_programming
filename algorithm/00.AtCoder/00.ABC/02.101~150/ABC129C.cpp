#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    map<int, int> mp;
    for (int i = 0; i < m; ++i) mp[a[i]]++;

    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; ++i) {
        if (i + 1 <= n) {
            if (mp[i+1] == 0) dp[i+1] += dp[i];
        }
        dp[i+1] %= MOD;
        if (i + 2 <= n) {
            if (mp[i+2] == 0) dp[i+2] += dp[i];
        }
        dp[i+2] %= MOD;
    }
    cout << dp[n] << endl;
}
