#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
vector<bool>seen;
vector<int> dp;

void dfs(const Graph& G, int v) {
    seen[v] = true;
    dp[v] = 1;

    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;
        dfs(G, nv);
        dp[v] += dp[nv];
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    vector<int> a(n), b(n);

    seen.assign(n, false);
    dp.assign(n, 0);

    for (int i = 0; i < n-1; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    dfs(G, 0);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long r = min(dp[a[i]], dp[b[i]]);
        ans += r * (n - r);
    }
    cout << ans << endl;
}
