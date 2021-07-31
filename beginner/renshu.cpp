#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
vector<int> dp;
vector<bool> seen;

void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto nv: G[v]) {
        if (seen[nv]==true) continue;

        dp[nv] += dp[v];
        dfs(G, nv);
    }
}

int main()
{
    int n, Q;
    cin >> n >> Q;
    dp.assign(n, 0);
    seen.assign(n, false);

    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int q = 0; q < Q; ++q) {
        int p, x;
        cin >> p >> x;
        p--;
        dp[p] += x;
    }

    dfs(G, 0);
    
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
}
