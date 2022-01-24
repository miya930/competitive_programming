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
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf;
    Graph G(n);
    uf.init(n);
    vector<map<int,bool>> mp;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        ans[i] = uf.size(i) - G[i].size() - 1;
    }

    for (int i = 0; i < k; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        if (uf.issame(c, d)) {
            ans[c]--;
            ans[d]--;
        }
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
