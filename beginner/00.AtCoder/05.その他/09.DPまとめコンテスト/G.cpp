#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
vector<bool> seen;
vector<int> post_order, dp(100010, 0);

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);
    }
    post_order.push_back(v);

    for (auto nv : G[v]) {
        chmax(dp[v], dp[nv] + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
    }

    for (int i = 0; i < n; ++i) {
        if (seen[i] == true) continue;
        dfs(G, i);
    }


    int ans = 0;
    for (int i = 0; i < n; ++i) chmax(ans, dp[i]);
    cout << ans << endl;
}