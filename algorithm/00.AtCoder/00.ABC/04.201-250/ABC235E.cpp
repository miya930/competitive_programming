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

UnionFind uf;

int main()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    uf.init(n);

    vector<pair<ll, pair<int,pair<int,int>>>> pa;

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        pa.push_back({c, {-1, {a, b}}});
    }

    for (int q = 0; q < Q; ++q) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        pa.push_back({w, {q, {u, v}}});
    }

    sort(pa.begin(), pa.end());

    int si = pa.size();
    vector<bool> ans(Q, false);
    for (int i = 0; i < si; ++i) {
        int x = pa[i].second.second.first;
        int y = pa[i].second.second.second;
        int q = pa[i].second.first;
        ll w = pa[i].first;

        if (uf.issame(x, y)) continue;
        if (q != -1) {
            ans[q] = true;
        } else {
            uf.unite(x, y);
        }
    }

    for (int i = 0; i < Q; ++i) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
