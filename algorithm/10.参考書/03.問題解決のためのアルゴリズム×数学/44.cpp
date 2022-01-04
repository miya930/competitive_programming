#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> que;
    vector<int> dist(n, -1);
    que.push(0);
    dist[0] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << dist[i] << endl;
    }

    return 0;
}
