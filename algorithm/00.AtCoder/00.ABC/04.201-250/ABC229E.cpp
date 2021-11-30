#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

struct UnionFind {
    vector<int> par, siz;

    void init(int n) {
        par.assign(n, -1);
        siz.assign(n, 1);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

};

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFind uf;
    uf.init(n);
    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> seen(n, false);
    vector<int> ans(n, 0);
    seen[n-1] = true;
    ans[n-1] = 0;
    int cnt = 0;
    for (int i = n-2; i >= 0; --i) {
        int ii = i+1;
        seen[ii] = true;
        cnt++;
        int unit = 0;
        for (auto nv : G[ii]) {
            if (seen[nv]) {
                if (!uf.issame(ii, nv)) unit++;
                uf.unite(ii, nv);
            }
        }
        cnt -= unit;
        ans[i] = cnt;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
