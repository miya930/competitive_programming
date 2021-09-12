#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n;++i) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> sum(n+1, 0), dp(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        dp[i+1]++;
        if (a[i+1] <= sum[i+1]*2) dp[i+1] += dp[i];
    }
    cout << dp[n-1] << endl;
    return 0;

}
