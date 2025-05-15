#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.unite(u, v);
    }
    int k;
    cin >> k;
    map<pair<int,int>, bool> mp;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int xr = uf.root(x);
        int yr = uf.root(y);
        mp[make_pair(xr, yr)] = true;
        mp[make_pair(yr, xr)] = true;
    }
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        int sr = uf.root(s);
        int tr = uf.root(t);
        if (mp.count(make_pair(sr, tr))) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
