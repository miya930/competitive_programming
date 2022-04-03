
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
vector<ll> dist1(2010, infl), dist2(2010, infl);
priority_queue<P, vector<P>, greater<P>> que;

void dijkstra(const Graph &G, int x, vector<ll> &dist) {
    dist[x] = 0;
    que.push(P(0, x));

    while(!que.empty()) {
        int v = que.top().second;
        ll  d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G1(n), G2(n);
    vector<ll> vec(n, infl);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G1[a].push_back(Edge{b, c});
        G2[b].push_back(Edge{a, c});
        if (a == b) vec[a] = min(vec[a], c);
    }

    for (int i = 0; i < n; ++i) {
        dist1.assign(n, infl);
        dist2.assign(n, infl);
        dijkstra(G1, i, dist1);
        dijkstra(G2, i, dist2);
        ll ans = infl;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (dist1[j] == infl || dist2[j] == infl) continue;
            ans = min(ans, dist1[j] + dist2[j]);
        }
        if (vec[i] != infl) ans = min(ans, vec[i]);

        if (ans >= infl) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}
