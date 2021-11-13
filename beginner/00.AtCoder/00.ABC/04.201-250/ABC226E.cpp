#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 998244353;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v, int &vcnt, int &ecnt) {
    seen[v] = true;
    vcnt++;

    for (auto nv : G[v]) {
        ecnt++;
        if (seen[nv]) continue;
        dfs(G, nv, vcnt, ecnt);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (seen[i]) continue;
        int vtemp = 0;
        int etemp = 0;
        c++;
        dfs(G, i, vtemp, etemp);
        if (2*vtemp != etemp) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    for (int i = 0; i < c;++i) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

