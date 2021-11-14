#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
typedef vector<vector<int> > make_g;
priority_queue<P, vector<P>, greater<P> > que;
queue<int> make_que;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int a[10000], b[10000], c[10000], r[10000];
Graph G(10000);
make_g GG(10000);
int make_dist[10000];
ll dist[10000];

void dijkstra(int s) {
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

void bfs(int s) {
    make_dist[s] = 0;
    make_que.push(s);

    while (!make_que.empty()) {
        int v = make_que.front();
        make_que.pop();

        for (auto nv : GG[v]) {
            if (make_dist[nv] != -1) continue;

            make_dist[nv] = make_dist[v] + 1;

            if (make_dist[nv] <= r[s]) {
                G[s].push_back(Edge(nv, c[s]));
            }

            make_que.push(nv);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) dist[i] = INF;

    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> r[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        GG[a[i]].push_back(b[i]);
        GG[b[i]].push_back(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) make_dist[j] = -1;
        bfs(i);
    }

    dijkstra(0);

    cout << dist[n - 1] << endl;
}
