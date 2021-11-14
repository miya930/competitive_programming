#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
const int mod = 1000000007;

vector<vector<long long> > dp;          // dp[i][j]：頂点iを根とする色の組み合わせの総数. jは色を表す (0：黒, 1：白)
vector<bool> seen;

void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {              // 探索済みでない子頂点のみについて色の組み合わせを計算したいため
        if (seen[nv] == true) continue;
        dfs(G, nv);
        dp[v][0] = dp[v][0] * (dp[nv][0] + dp[nv][1]) % mod;
        dp[v][1] = dp[v][1] * dp[nv][0] % mod;
    }

    /**
     * ここにdpの処理を書くと子頂点のみでなく親頂点についても色の組み合わせの計算に入れてしまうため、結果が間違ってしまう。
     */

}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    dp.assign(n+1, vector<long long>(2, 1));
    seen.assign(n, false);

    dfs(G, 0);

    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}
