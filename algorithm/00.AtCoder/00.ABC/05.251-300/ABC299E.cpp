#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const int inf = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> ans(n, 1), isng(k, 1);
    vector<int> p(k), d(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i] >> d[i];
        p[i]--;
    }

    vector<int> dist(n, inf);
    for (int i = 0; i < k; i++) {
        dist.assign(n, inf);
        dist[p[i]] = 0;
        queue<int> que;
        que.push(p[i]);

        if (d[i] > 0) ans[p[i]] = 0;

        while(!que.empty()) {
            int v = que.front();
            que.pop();

            if (dist[v] >= d[i] - 1) break;

            for (auto nv : G[v]) {
                if (dist[nv] != inf) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
                ans[nv] = 0;
            }
        }
    }

    // check
    for (int i = 0; i < k; i++) {
        dist.assign(n, inf);
        dist[p[i]] = 0;
        queue<int> que;
        que.push(p[i]);

        while(!que.empty()) {
            int v = que.front();
            que.pop();

            if (dist[v] == d[i] && ans[v] == 1) {
                isng[i] = 0;
            }
            if (dist[v] >= d[i]) continue;

            for (auto nv : G[v]) {
                if (dist[nv] != inf) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    bool ng = false;
    for (int i = 0; i < k; i++) {
        if (isng[i] == 1) ng = true;
    }

    if (ng) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
    }

    return 0;
}
