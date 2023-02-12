#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
int c[2300];
int dist[2020][2020];
queue<pair<int,int>> que;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> c[i];
        vector<int> G[2010];
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) dist[i][j] = -1;
        }
        dist[0][n-1] = 0;

        que.push(make_pair(0, n-1));
        while(!que.empty()) {
            int v1 = que.front().first;
            int v2 = que.front().second;
            que.pop();

            for (auto nv1 : G[v1]) {
                for (auto nv2 : G[v2]) {
                    if (c[nv1] != c[nv2]) {
                        if (dist[nv1][nv2] == -1) {
                            dist[nv1][nv2] = dist[v1][v2] + 1;

                            que.push(make_pair(nv1, nv2));
                        }
                    }
                }
            }
        }

        cout << dist[n-1][0] << endl;
        
    }

    return 0;
}
