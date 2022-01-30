#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct Edge {
    int to;
    ll dist;
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    Graph G(n);

    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (h[u] > h[v]) {
            G[u].push_back(Edge{v, -1*abs(h[v]-h[u])});
            G[v].push_back(Edge{u, 2*abs(h[v]-h[u])});
        } else if (h[u] < h[v]) {
            G[u].push_back(Edge{u, 2*abs(h[u]-h[v])});
            G[v].push_back(Edge{v, -1*abs(h[u]-h[v])});
        } else {
            G[u].push_back(Edge{v, 0});
            G[v].push_back(Edge{u, 0});
        }
    }

    vector<ll> dist(n, infl);
    dist[0] = 0;
    for (int iter = 0; iter < n; ++iter) {
        bool update = false;
        for (int v = 0; v < n; ++v) {
            if (dist[v] == infl) continue;

            for (auto e : G[v]) {
                if (chmin(dist[e.to], dist[v] + e.dist)) {
                    update = true;
                }
            } 
        }
        if (!update) break;
    }    

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dist[i]);
        cout << "dist[" << i << "] = " << dist[i] << endl;
    }

    cout << -1*ans << endl;
    return 0;
}
