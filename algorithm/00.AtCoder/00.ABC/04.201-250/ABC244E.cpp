#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
using Graph = vector<vector<int>>;

ll dp[2020][2020][2];

int main()
{
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--; t--; x--;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dp[0][s][0] = 1;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) { // i項目、頂点j 
            for (auto nv : G[j]) {
                if (nv == x) {
                    dp[i+1][nv][0] = (dp[i+1][nv][0] + dp[i][j][1])%mod;
                    dp[i+1][nv][1] = (dp[i+1][nv][1] + dp[i][j][0])%mod;
                } else {
                    dp[i+1][nv][0] = (dp[i+1][nv][0] + dp[i][j][0])%mod;
                    dp[i+1][nv][1] = (dp[i+1][nv][1] + dp[i][j][1])%mod;
                }
            }
        }
    }

    cout << dp[k][t][0] << endl;
    return 0;
}
