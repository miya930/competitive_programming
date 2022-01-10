#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct Edge {
    ll to;
    ll dep;
    ll time;
};
using Graph = vector<vector<Edge>>;

template <class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
priority_queue<P, vector<P>, greater<P>> que;
vector<ll> dp;

void dijkstra(const Graph& G, int node) {
    que.push(P(0,node));
    dp[node] = 0;

    while(!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dp[v]) continue;

        for (auto e : G[v]) {
            ll dist = d + e.time;
            if (d%e.dep != 0) {
                dist += (e.dep - d%e.dep);
            }
            if (chmin(dp[e.to], dist)) {
                que.push(P(dist, e.to));
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    Graph G(n);

    for (int i = 0; i < m; ++i) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        G[a].push_back(Edge{b, k, t});
        G[b].push_back(Edge{a, k, t});
    }

    dp.assign(n+1, infl);
    dijkstra(G, x);

    if (dp[y] != infl) cout << dp[y] << endl;
    else cout << -1 << endl;
    return 0;
}
