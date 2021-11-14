#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<vector<int> > Graph;
Graph G;
vector<int> dist;
queue<int> que;

void bfs(Graph G, int x) {
    dist[x] = 0;
    que.push(x);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    G.resize(n);
    dist.assign(n, -1);

    for (int i = 1; i < n; ++i) {
        G[i].push_back(i - 1);
        G[i - 1].push_back(i);
    }
    G[x - 1].push_back(y-1);
    G[y - 1].push_back(x - 1);

    long long ans = 0;
    for (int k = 1; k < n; ++k) {
        ans = 0;
        for (int i = 0; i < n; ++i) {
            dist.assign(n, -1);
            bfs(G, i);
            for (int j = i + 1; j < n; ++j) {
                if (dist[j] == k) ans++;
            }
        }
        cout << ans << endl;
    }
}