#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<vector<int>> dp(4000, vector<int>(4000, -1));

int main()
{
    int s ,t, m;
    cin >> s >> t >> m;
    Graph G(s+t);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v-s);
        G[v].push_back(u-s);
    }

    for (int i = 0; i < s; i++) {
        for (auto& u : G[i]) {
            for (auto& v : G[i]) {
                if (u == v) continue;
                if (dp[u][v] != -1) {
                    cout << i + 1 << " " << dp[u][v] + 1 << " ";
                    cout << u + s + 1 << " " << v + s + 1 << endl;
                    exit(0);
                }
                dp[u][v] = i;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
