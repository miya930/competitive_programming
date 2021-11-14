#include <iostream>
#include <vecstor>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;
vector<ll> dist, dist_;
priority_queue<P, vector<P>, greater<P> > que;
priority_queue<ll> que_A;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void dijkstra(const Graph &G, int x, vector<ll> dist) {
    dist[x] = 0;
    que.push(P(dist[x], x));

    while(!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v]+e.w)) {
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    dist.assign(n, INF);
    dist_.assign(n, INF);
    vector<int> a(n);
    Graph G(n);
    Graph G_(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge(b, c));
        G_[b].push_back(Edge(a, c));
    }

    ll ans = 0;
    
    dijkstra(G, 0, dist);
    dijkstra(G_, 0, dist_);
    
    for (int i = 0; i < n; ++i) {
        ll x = dist[i];
        ll y = dist_[i];
        if (t > x + y) ans = max(ans, a[i]*(t - x - y));
    }
    cout << ans << endl;

}
