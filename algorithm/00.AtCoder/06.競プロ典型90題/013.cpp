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

    // �_0 ����k�܂ł̋���
    dy(G, 0);
    for (int i = 0; i < n; ++i) vec_to_k[i] = dist[i];

    // k����_N�܂ł̋����̌v�Z
    dy(G, n - 1);
    for (int i = 0; i < n; ++i) vec_from_k[i] = dist[i];

    for (int i = 0; i < n; ++i) {
        cout << vec_to_k[i] + vec_from_k[i] << endl;
    }

}



/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

struct Edge {
    int to;
    ll w;
};

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

using Graph = vector<vector<Edge>>;
priority_queue<P, vector<P>, greater<P>> que;
vector<ll> dist;

void dijkstra(const Graph &G, int x) {
    dist[x] = 0LL;
    que.push(P(0LL, x));

    while(!que.empty()) {
        int v = que.top().second;
        ll  d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], d + e.w)) {
                que.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    dist.assign(n, infl);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(Edge{b, c});
        G[b].push_back(Edge{a, c});
    }

    vector<ll> ans(n, 0);
    dijkstra(G, 0);
    for (int i = 0; i < n; ++i) ans[i] += dist[i];
    dist.assign(n, infl);
    dijkstra(G, n-1);
    for (int i = 0; i < n; ++i) ans[i] += dist[i];

    for (int i = 0; i < n; ++i) cout << ans[i] << endl;

    return 0;
}
