#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

struct Edge {
    ll w;
    int to;
    Edge(ll w, int to): w(w), to(to) {}
};
using Graph = vector<vector<Edge>>;

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
    int n;
    cin >> n;
    Graph G(n);
    rep(i, 0, n-1) {
        ll a, b, x;
        cin >> a >> b >> x;
        x--;
        G[i].push_back(Edge(a, i+1));
        G[i].push_back(Edge(b, x));
    }

    vector<ll> dist(n, infl);
    dijkstra(G, 0, dist);
    cout << dist[n-1] << endl;

    return 0;
}
