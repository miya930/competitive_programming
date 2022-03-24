// https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<bool> seen;
vector<ll> ans, c;
int idx = 0;
ll sum = 0;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);
    }

    ans[v] = c[idx];
    idx++;    
}

void dfs1(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs1(G, nv);

        sum += min(ans[v], ans[nv]);
    }
}

int main()
{
    int n;
    cin >> n;
    seen.assign(n, false);
    ans.assign(n, 0);
    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    c.resize(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    sort(c.begin(), c.end());

    dfs(G, 0);
    seen.assign(n, false);
    dfs1(G, 0);

    cout << sum << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
