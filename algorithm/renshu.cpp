#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const int inf = 2001001001;

int main()
{
    int n,m;
    cin >> n >> m;
    Graph G(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }

    vector<int> dp(n, inf);
    for (int i = 0; i < n; ++i) {
        for (auto x : G[i]) {
            dp[x] = min(dp[x], min(dp[i],a[i]));
        }
    }

    int ans = -inf/2;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, a[i]-dp[i]);
    }
    cout << ans << endl;
    return 0;
}
