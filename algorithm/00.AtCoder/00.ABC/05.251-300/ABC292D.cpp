#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> verseen;
map<pair<int,int>, int> mp, mpcnt;
int edgecnt = 0;
int vercnt = 0;

void dfs(vector<vector<int>> &G, int v, vector<bool> &seen) {
    seen[v] = true;
    edgecnt++;

    for (auto nv : G[v]) {
        int miv = min(v, nv);
        int mav = max(v, nv);

        if (mpcnt[make_pair(miv, mav)] > 0) {
            mpcnt[make_pair(miv, mav)]--;
            vercnt++;
        }

        if (seen[nv]) continue;

        dfs(G, nv, seen);
    }
}

int main()
{
    int n, m;
    cin >> n  >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);

        if (u > v) swap(u, v);
        mpcnt[make_pair(u, v)]++;
    }

    vector<bool> seen(n, false);
    verseen.assign(m, false);

    bool issame = true;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;

        edgecnt = 0;
        vercnt = 0;
        dfs(G, i, seen);

        if (edgecnt != vercnt) issame = false;
    }

    if (issame) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
