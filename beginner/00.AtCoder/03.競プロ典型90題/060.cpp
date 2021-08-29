#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> mi = a;
    reverse(mi.begin(), mi.end());

    vector<int> dp(n+1, INF), dpm(n+1, INF);
    vector<int> sum(n+1, 0), msum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        auto it2 = lower_bound(dpm.begin(),dpm.end(), mi[i]) - dpm.begin();
        dp[it] = a[i];
        dpm[it2] = mi[i];
        sum[i] = it + 1;
        msum[i] = it2 + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, sum[i] + msum[n-i-1] - 1);
    }
    cout << ans << endl;
    return 0;
}
