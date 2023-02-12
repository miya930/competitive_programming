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
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
        uf.unite(u, v);
    }

    int one = 0, two = 0;
    bool ispath = false;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0 || deg[i] >= 3) {
            break;
        }
        if (deg[i] == 1) one++;
        else if (deg[i] == 2) two++;
    }

    if (one == 2 && two == n-2) ispath = true;

    for (int i = 1; i < n; i++) {
        if (!uf.issame(0, i)) {
            ispath = false;
            break;
        }
    }

    if (ispath) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
