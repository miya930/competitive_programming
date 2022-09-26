#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<int> before;
vector<bool> seen;
queue<int> que;

void bfs(const Graph G, int vv) {
    que.push(vv);

    while(!que.empty()) {
        int v = que.front();
        que.pop();
        seen[v] = true;

        for (auto nv : G[v]) {
            if (seen[nv] == true) continue;

            before[nv] = v;
            que.push(nv);
        }
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;

    Graph G(n);
    seen.assign(n, false);
    before.assign(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> ans;
    bfs(G, x);

    int cur = y;
    ans.push_back(cur);
    while(1) {
        int v = before[cur];
        ans.push_back(v);

        if (v == x) break;
        cur = v;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i]+1 << " ";
    cout << endl;

    return 0;
}
