#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph G0(n), G1(n);
    map<int,int> s;
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        if (a == 0) {
            G0[u].push_back(v);
            G0[v].push_back(u);
        } else {
            G1[u].push_back(v);
            G1[v].push_back(u);
        }
    }
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        t--;
        s[t]++;
    }

    vector<vector<int>> dist(2, vector<int>(n, -1));
    dist[1][0] = 0;
    queue<pair<int,int>> que;
    que.push(make_pair(0, 1));

    if (s.count(0)) {
        dist[0][0] = 0;
        que.push(make_pair(0, 0));
    }

    while(!que.empty()) {
        int v = que.front().first;
        int a = que.front().second;
        que.pop();

        if (a == 0) {
            for (auto nv : G0[v]) {
                if (dist[a][nv] != -1) continue;
                
                que.push(make_pair(nv, a));
                dist[a][nv] = dist[a][v] + 1;
                if (s.count(nv)) {
                    que.push(make_pair(nv, 1-a));
                    dist[1-a][nv] = dist[a][v] + 1;
                }
            }
        } else {
            for (auto nv : G1[v]) {
                if (dist[a][nv] != -1) continue;

                que.push(make_pair(nv, a));
                dist[a][nv] = dist[a][v] + 1;
                if (s.count(nv)) {
                    que.push(make_pair(nv, 1-a));
                    dist[1-a][nv] = dist[a][v] + 1;
                }
            }
        }
    }
    int ans = 1001001001;
    if (dist[0][n-1] != -1) ans = min(ans, dist[0][n-1]);
    if (dist[1][n-1] != -1) ans = min(ans, dist[1][n-1]);

    if (ans == 1001001001) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
