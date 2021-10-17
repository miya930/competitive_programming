#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;
const int BASE = 100005;
using Graph = vector<vector<pair<int, int> > >;

int n, m, k;
vector<int> dist, memo;
Graph G;
vector<int> a;
vector<int> cnt;
vector<vector<int> > dp(2, vector<int>(201010));

bool dfs(int cu, int pa, int g) {
    if (cu == g) return true;

    for(auto e : G[cu]) {
        if (e.first == pa) continue;
        bool res = dfs(e.first, cu, g);
        if (res) {
            cnt[e.second]++;
            return true;
        }
    }
    
    return false;
}

int main()
{
    cin >> n >> m >> k;
    G.resize(n);
    a.resize(m);
    cnt.assign(n-1, 0);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }

    for (int i = 0; i < m-1; ++i) dfs(a[i], -1, a[i+1]);

    dp[0][BASE] = 1;

    for (int i = 0; i < n-1; ++i) {
        int cu = i%2;
        int nxt = 1 - cu;
        for (int tot = 0; tot < 201010; ++tot) dp[nxt][tot] = 0;
        for (int tot = 0; tot < 201010; ++tot) {
            if (tot-cnt[i] < 0) continue;
            dp[nxt][tot-cnt[i]] += dp[cu][tot];
            dp[nxt][tot-cnt[i]] %= mod;
            dp[nxt][tot+cnt[i]] += dp[cu][tot];
            dp[nxt][tot+cnt[i]] %= mod;
        }
    }

    cout << dp[(n-1)%2][k+BASE] << endl;
    return 0;
}
