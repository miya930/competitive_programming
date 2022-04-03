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
    int n, m;
    cin >> n >> m;
    uf.init(n);

    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.unite(x, y);
    }

    int ans = 0;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; ++i) {
        int v = uf.root(i);
        if (seen[v] == true) continue;
        seen[v] = true;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
