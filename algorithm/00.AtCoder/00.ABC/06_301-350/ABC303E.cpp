#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    vector<int> deg(n, 0), seen(n, false);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) que.push(i);
    }

    vector<int> ans;
    while(!que.empty()) {
        int v = que.front();
        que.pop();

        if (seen[v]) continue;

        int nv = G[v][0];
        for (int i = 0; i < G[v].size(); i++) {
            if (seen[G[v][i]]) continue;
            nv = G[v][i];
        }
        int de = deg[nv];

        ans.push_back(deg[nv]);
        seen[nv] = true;
        seen[v] = true;
        for (auto nex : G[nv]) {
            if (seen[nex]) continue;
            seen[nex] = true;

            for (auto nnv : G[nex]) {
                if (seen[nnv]) continue;
                deg[nnv]--;

                if (deg[nnv] == 1) que.push(nnv);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
