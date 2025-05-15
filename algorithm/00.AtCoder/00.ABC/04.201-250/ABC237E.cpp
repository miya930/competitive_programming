#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<vector<Edge>> G(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back({v, max(0LL, h[v] - h[u])});
        G[v].push_back({u, max(0LL, h[u] - h[v])});
    }

    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    vector<ll> dist(n, infl);
    que.push(make_pair(0LL, 0));
    dist[0] = 0;

    while(!que.empty()) {
        int v = que.top().second;
        ll w = que.top().first;
        que.pop();

        if (dist[v] < w) continue;
        for (auto e : G[v]) {
            if (dist[e.to] > dist[v] + e.w) {
                dist[e.to] = dist[v] + e.w;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dist[i] += h[i];
    }
    ll ans = infl;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist[i]-h[0]);
    }
    cout << -ans << endl;
    return 0;
}
