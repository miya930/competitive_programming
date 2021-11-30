#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int, ll>>>;

vector<ll> dist;
queue<int> que;

void bfs(const Graph &G, int x) {
    dist[x] = 0;
    que.push(x);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv.first] != -1) continue;
            dist[nv.first] = dist[v] + nv.second;
            que.push(nv.first);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    dist.assign(n, -1);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    bfs(G, K);
    for (int q = 0; q < Q; ++q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        
        cout << dist[x] + dist[y] << endl;
    }

    return 0;
}
