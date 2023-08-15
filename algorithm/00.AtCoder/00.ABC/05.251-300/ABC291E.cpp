#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

struct Edge {
    ll w;
    int to;
    Edge(ll w, int to): w(w), to(to) {}
};

void dijkstra(vector<vector<Edge>> &G, int x, vector<ll> &dist) {
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    dist[x] = 0;
    que.push(make_pair(0, x));

    while(!que.empty()) {
        ll w = que.top().first;
        int v = que.top().second;
        que.pop();

        if (w > dist[v]) continue;

        for (auto e : G[v]) {
            if (dist[e.to] > w + e.w) {
                dist[e.to] = w + e.w;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u].push_back(Edge(w, v));
    }

    vector<ll> dist(n, INF);
    dijkstra(G, 0, dist);
    
    for (int i = 0; i < n; i++) {
        cout << dist[i] << endl;
    }

    return 0;
}
