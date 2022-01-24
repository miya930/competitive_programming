#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL<<60;

struct Edge {
    int v;
    ll time;
    ll start;
};

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

priority_queue<P, vector<P>, greater<P>> que;
vector<ll> dist;
vector<vector<Edge>> edge;

void dijkstra(int x) {
    dist[x] = 0LL;
    que.push({0LL, x});

    while(!que.empty()) {
        int xx = que.top().second;
        ll d = que.top().first;
        que.pop();
        if (dist[xx] < d) continue;

        for (auto e : edge[xx]) {
            ll nd = dist[xx] + e.time;
            if (dist[xx]%e.start != 0) {
                nd += (e.start - dist[xx]%e.start);
            }
            if (chmin(dist[e.v], nd)) {
                que.push(P(dist[e.v], e.v));
            }
        }
    }
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    edge.resize(n);
    dist.assign(n, infl);

    for(int i = 0; i < m; ++i) {
        int a, b;
        ll t, k;
        cin >> a >> b >> t >> k;
        a--; b--;
        edge[a].push_back(Edge{b, t, k});
        edge[b].push_back(Edge{a, t, k});
    }

    dijkstra(x);

    if (dist[y] != infl) cout << dist[y] << endl;
    else cout << -1 << endl;

    return 0;
}
