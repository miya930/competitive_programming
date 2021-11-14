#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;
const int BASE = 100005;
using Graph = vector<vector<int> >;

int n, m, k;
vector<int> dist, memo;
map<pair<int, int>, int> cnt;
Graph G;
vector<int> a;
queue<int> que;
vector<vector<int> > dp(2, vector<int>(201010, 0));

void bfs(const Graph &G , int s, int g) {
    que.push(s);
    dist[s] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            memo[nv] = v;
            if (nv == g) {
                while (!que.empty()) {
                    que.pop();
                }
                return;
            }

            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    G.resize(n);
    a.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < m-1; ++i) {
        if (a[i] == a[i+1]) continue;
        dist.assign(n, -1);
        memo.assign(n, -1);
        bfs(G, a[i], a[i+1]);
        
        int start = a[i], path = a[i+1];
        
        while (path != start) {
            int temp1 = path;
            int temp2 = memo[path];

            if (temp1 > temp2) swap(temp1, temp2);
            cnt[make_pair(temp1, temp2)]++;

            path = memo[path];
        }
    }
    
    vector<int> count(n-1, 0);
    int ii = 0;
    for (auto x : cnt) {
        count[ii] = x.second;
        ii++;
    }

    dp[0][BASE] = 1;

    for (int i = 0; i < n-1; ++i) {
        int cu = i%2;
        int nxt = 1 - cu;
        for (int tot = 0; tot < 201010; ++tot) dp[nxt][tot] = 0;
        for (int tot = 0; tot < 201010; ++tot) {
            if (tot-count[i] < 0) continue;
            dp[nxt][tot-count[i]] += dp[cu][tot];
            dp[nxt][tot-count[i]] %= mod;
            dp[nxt][tot+count[i]] += dp[cu][tot];
            dp[nxt][tot+count[i]] %= mod;
        }
    }

    cout << dp[(n-1)%2][k+BASE] << endl;
    return 0;
}
