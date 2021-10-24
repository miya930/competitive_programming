/**
   created: 21.10.2021 21:49:07
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int> >;
const int inf = 1001001001;
const ll infl = 1LL << 60;

vector<bool> seen;
vector<ll> vec, a, b;

void dfs(const Graph &G, int v, ll &asum, ll &bsum) {
    seen[v] = true;
    asum += a[v];
    bsum += b[v];

    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;

        dfs(G, nv, asum, bsum);
    }
}

int main()
{
    int n ,m;
    cin >> n >> m;
    a.assign(n, 0);
    b.assign(n, 0);

    seen.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        G[c].push_back(d);
        G[d].push_back(c);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (seen[i] != 0) continue;
        ll asum = 0, bsum = 0;
        dfs(G, i, asum, bsum);

        if (asum != bsum) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
