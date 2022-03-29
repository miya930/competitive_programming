#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct Edge {
    int to;
    ll w;
};

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

using Graph = vector<vector<Edge>>;
Graph edge;
priority_queue<P, vector<P>, greater<P>> que;
vector<ll> dist;

void dijkstra(const Graph &G, int x) {
    dist[x] = 0;
    que.push(P(0, x));

    while(!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (dist[v] < d) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v]+e.w)) {
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    edge.resize(n);
    dist.assign(n, infl);
    for (int i = 0; i < n; ++i) cin >> h[i];

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int hu = h[u];
        int hv = h[v];
        if (hu > hv) {
            edge[u].push_back(Edge{u, hu+hv});
            edge[v].push_back(Edge{v, 2*hu});
        } else if (hu < hv) {
            edge[u].push_back(Edge{v, 2*hu});
            edge[v].push_back(Edge{u, hu+hv});
        }
    }

    dijkstra(edge, 0);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;
    return 0;
}
