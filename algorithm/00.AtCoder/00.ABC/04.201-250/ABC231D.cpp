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
    vector<int> deg(n, 0);

    UnionFind uf;
    uf.init(n);

    bool flag = true;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (uf.issame(a, b)) flag = false;

        uf.unite(a, b);
        deg[a]++;
        deg[b]++;
    }

    for (int i = 0; i < n; ++i) {
        if (deg[i] > 2) flag = false;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
