#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
typedef vector<vector<int> > Graph;

long long mod = 1000000007;
long long dp[1 << 18][3];
char c[1 << 18];

vector<bool> seen;

void dfs(const Graph& G, int v) {
    seen[v] = true;
    long long val1 = 1, val2 = 1;
    for (int nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);

        if (c[v] == 'a') {
            val1 *= (dp[nv][0] + dp[nv][2]);
            val2 *= (dp[nv][0] + dp[nv][1] + 2LL * dp[nv][2]);
        }
        if (c[v] == 'b') {
            val1 *= (dp[nv][1] + dp[nv][2]);
            val2 *= (dp[nv][0] + dp[nv][1] + 2LL * dp[nv][2]);
        }
        val1 %= mod;
        val2 %= mod;
    }

    if (c[v] == 'a') {
        dp[v][0] = val1;
        dp[v][2] = (val2 - val1 + mod) % mod;
    }
    if (c[v] == 'b') {
        dp[v][1] = val1;
        dp[v][2] = (val2 - val1 + mod) % mod;
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    seen.assign(n, false);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G, 0);
    cout << dp[0][2] << endl;
    return 0;
}
