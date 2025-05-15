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
using Graph = vector<vector<int>>;
vector<int> dist;

void bfs(Graph &G, int v) {
    dist[v] = 0;
    queue<int> que;
    que.push(v);

    while(!que.empty()) {
        int x = que.front();
        que.pop();

        for (auto nv : G[x]) {
            if (dist[nv] != inf) continue;
            dist[nv] = dist[x] + 1;
            que.push(nv);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    dist.resize(n, inf);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    bfs(G, 0);

    int ans = inf;
    for (int i = 1; i < n; i++) {
        for (auto v : G[i]) {
            if (v == 0) {
                ans = min(dist[i]+1, ans);
            }
        }
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

}
