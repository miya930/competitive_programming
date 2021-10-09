/**
   created: 09.10.2021 23:27:04
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 998244353;
using Graph = vector<vector<int> >;

queue<int> que;
vector<int> dist;
map<pair<int, int>, int> cnt;

void bfs(const Graph &G , int s, int g) {
    que.push(s);
    dist[s] = 0;

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            int mi = min(v, nv), ma = max(v, nv);
            cnt[make_pair(mi, ma)]++;

            if (nv == g) return;

            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    Graph G(n+1);

    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < m-1; ++i) {
        dist.assign(n, -1);
        bfs(G, a[i], a[i+1]);
    }

    for (auto x : cnt) {
        cout << "u = " << x.first.first << "   v = " << x.first.second << "  count = " << x.second << endl;
    }

    return 0;
}
