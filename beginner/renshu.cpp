#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;
typedef vector<vector<Edge> > Graph;

vector<ll> dist1, dist2;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void dijkstra(const Graph& G, int s) {
    dist1[s] = 0;
    que.push(make_pair(dist1[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist2[v]) continue;

        for (int i = 0; i < G[v].size(); ++i) {
            Edge e = G[v][i];
            ll d2 = d + e.w;
            if (dist1[e.to] > d2) {
                swap(dist1[e.to], d2);
                que.push(make_pair(dist1[e.to], e.to));
            }

            if (dist1[e.to] < d2 && dist2[e.to] > d2) {
                dist2[e.to] = d2;
                que.push(make_pair(dist2[e.to], e.to));
            }
        }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    dist1.assign(n, INF);
    dist2.assign(n, INF);

    for (int i = 0; i < m; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        s--; t--;
        G[s].push_back(Edge(t, d));
        G[t].push_back(Edge(s, d));
    }

    dijkstra(G, 0);

    cout << dist2[n - 1] << endl;
}
