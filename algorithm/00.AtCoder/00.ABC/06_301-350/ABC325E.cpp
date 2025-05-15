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
    ll car;
    ll train;
    int to;
    Edge(ll car, ll train, int to): car(car), train(train), to(to) {}
};

void dijkstra(vector<vector<Edge>> &G, int x, vector<vector<ll>> &dist) {
    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> que;
    dist[x][0] = 0;
    dist[x][1] = 0;
    que.push(make_pair(0, make_pair(0, 2)));

    while(!que.empty()) {
        ll w = que.top().first;
        int v = que.top().second.first;
        int cort = que.top().second.second; // 1:train, 2:car
        que.pop();

        int vv;
        if (cort == 1) vv = 1;
        else vv = 0;
        if (w > dist[v][vv]) continue;

        for (auto e : G[v]) {
            ll cdist = w + e.car;
            ll tdist = w + e.train;
            if (cort == 1) {
                if (dist[e.to][1] > tdist) {
                    dist[e.to][1] = tdist;
                    que.push(make_pair(dist[e.to][1], make_pair(e.to, 1)));
                }
            } else {
                if (dist[e.to][1] > tdist) {
                    dist[e.to][1] = tdist;
                    que.push(make_pair(dist[e.to][1], make_pair(e.to, 1)));
                }
                if (dist[e.to][0] > cdist) {
                    dist[e.to][0] = cdist;
                    que.push(make_pair(dist[e.to][0], make_pair(e.to, 2)));                    
                }                
            }
        }
    }

}

int main()
{
    int n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n)), cost(n, vector<ll>(n, 0));
    vector<vector<Edge>> G(n);
    rep(i, 0, n) rep(j, 0, n) {
        cin >> d[i][j];
    }
    rep(i, 0, n) rep(j, i+1, n) {
        ll car = d[i][j] * a;
        ll train = d[i][j] * b + c;
        G[i].push_back(Edge(car, train, j));
        G[j].push_back(Edge(car, train, i));
    }

    vector<vector<ll>> dist(n, vector<ll>(2, infl));
    dijkstra(G, 0, dist);
    cout << min(dist[n-1][0], dist[n-1][1]) << endl;

    return 0;
}
