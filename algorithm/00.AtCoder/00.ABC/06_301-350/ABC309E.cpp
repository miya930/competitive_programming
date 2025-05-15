#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen, hoken;
vector<int> res;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);
    hoken.assign(n, false);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }
    res.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        res[x] = max(res[x], y+1);
    }
    queue<int> que;
    que.push(0);
    int s = res[0];
    while(!que.empty()) {
        int v = que.front();
        que.pop();

        s = res[v];

        if (s > 0) hoken[v] = true;

        for (auto nv : G[v]) {
            if (seen[nv]) continue;
            res[nv] = max(s-1,res[nv]);
            seen[nv] = true;
            que.push(nv);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (hoken[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
