#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<long long> dist;
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > que;

int n, m;

void dy(const Graph& G, int x) {
    dist.assign(n, INF);
    dist[x] = 0;
    que.push(make_pair(dist[x], x));

    while (!que.empty()) {
        int v = que.top().second;
        long long d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    Graph G(n);
    vector<long long> vec_to_k(n, 0), vec_from_k(n, 0);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        G[a].push_back(Edge(b, c));
        G[b].push_back(Edge(a, c));
    }

    // “_0 ‚©‚çk‚Ü‚Å‚Ì‹——£
    dy(G, 0);
    for (int i = 0; i < n; ++i) vec_to_k[i] = dist[i];

    // k‚©‚ç“_N‚Ü‚Å‚Ì‹——£‚ÌŒvŽZ
    dy(G, n - 1);
    for (int i = 0; i < n; ++i) vec_from_k[i] = dist[i];

    for (int i = 0; i < n; ++i) {
        cout << vec_to_k[i] + vec_from_k[i] << endl;
    }

}
