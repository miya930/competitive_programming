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

    vector<int> a(m), b(m), c(n);
    UnionFind uf;
    uf.init(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < m; i++) {
        int s = a[i];
        int t = b[i];
        if (c[s] != c[t]) {
            uf.unite(s, t);
        }
    }
    for (int i = 0; i < m; i++) {
        int s = a[i];
        int t = b[i];
        if (uf.issame(s, t) && c[s] == c[t]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;

    return 0;
}
