#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;
typedef vector<vector<int> > d_Graph;

vector<ll> dist;
vector<int> d_dist;
vector<bool> danger;
queue<int> d_que;
priority_queue<P, vector<P>, greater<P> > que;
int n, m, k, s;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void bfs(const d_Graph& G, int x) {
    d_dist[x] = 0;
    d_que.push(x);

    while (!d_que.empty()) {
        int v = d_que.front();
        d_que.pop();

        for (auto nv : G[v]) {
            if (d_dist[nv] != -1) continue;
            d_dist[nv] = d_dist[v] + 1;
            if (d_dist[nv] <= s) danger[nv] = true;
            if (d_dist[n] > s) continue;
            d_que.push(nv);
        }
    }
}

void dijkstra(const Graph& G, int s) {
    dist[s] = 0;
    que.push(P(dist[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
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
    cin >> n >> m >> k >> s;

    dist.assign(n, INF);
    danger.assign(n, false);
    Graph G(n);
    d_Graph d_G(n);

    int p, q;
    cin >> p >> q;

    map<int, int>  mp;

    for (int i = 0; i < k; ++i) {
        int dd; cin >> dd;
        dd--;
        mp[dd]++;
    }

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        d_G[a[i]].push_back(b[i]);
        d_G[b[i]].push_back(a[i]);
    }

    for (auto i : mp) {
        d_dist.assign(n, -1);
        bfs(d_G, i.first);
    }

    for (int i = 0; i < m; ++i) {
        if (mp[a[i]] || mp[b[i]]) continue;
        
        if (b[i] == n - 1 || b[i] == 0)  G[a[i]].push_back(Edge(b[i], 0));
        else if (danger[b[i]] == true) G[a[i]].push_back(Edge(b[i], q));
        else G[a[i]].push_back(Edge(b[i], p));

        if (a[i] == n - 1 || a[i] == 0) G[b[i]].push_back(Edge(a[i], 0));
        else if (danger[a[i]] == true) G[b[i]].push_back(Edge(a[i], q));
        else G[b[i]].push_back(Edge(a[i], p));
    }

    dijkstra(G, 0);

    cout << dist[n - 1] << endl;
    return 0;
}
