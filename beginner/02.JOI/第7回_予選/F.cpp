#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;
vector<ll> dist;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void dijkstra(const Graph& G, int x) {
    dist[x] = 0;
    que.push(make_pair(dist[x], x));

    while (!que.empty()) {
        int v = que.top().second;
        ll w = que.top().first;
        que.pop();

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> ans;
    dist.assign(n, INF);
    Graph G(n);

    for (int i = 0; i < k; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (!t) {
            dist.assign(n, INF);
            dijkstra(G, a);

            if (dist[b] < INF) ans.push_back(dist[b]);
            else ans.push_back(-1);
        }
        else {
            ll e;
            cin >> e;
            G[a].push_back(Edge(b, e));
            G[b].push_back(Edge(a, e));
        }
    }

    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << endl;

    return 0;
}