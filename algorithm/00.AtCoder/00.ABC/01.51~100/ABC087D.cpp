#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): w(w), to(to) {}
};

using Graph = vector<vector<Edge>>;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n), GR(n);
    vector<bool> seen(n, false);
    vector<ll> dist(n, infl);
    for (int i = 0; i < m; i++) {
        int l, r;
        ll w;
        cin >> l >> r >> w;
        l--; r--;
        G[l].push_back(Edge(r, w));
        GR[r].push_back(Edge(l, w));
    }


    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
        dist[i] = 0;
        seen[i] = 1;
        que.push(make_pair(0, i));

        while(!que.empty()) {
            ll w = que.top().first;
            int v = que.top().second;
            que.pop();

            for (auto e : G[v]) {
                if (seen[e.to]) {
                    if (dist[e.to] != w + e.w) {
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    dist[e.to] = w + e.w;
                    que.push(make_pair(dist[e.to], e.to));
                    seen[e.to] = true;
                }
            }

            for (auto e : GR[v]) {
                if (seen[e.to]) {
                    if (dist[e.to] != w - e.w) {
                        cout << "No" << endl;
                        return 0;
                    }
                } else {
                    dist[e.to] = w - e.w;
                    que.push(make_pair(dist[e.to], e.to));
                    seen[e.to] = true;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}
