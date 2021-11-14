#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        return y;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);

    UnionFind uf;

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        uf.init(n);
        int temp = 0;
        for (int j = 0; j < m; ++j) {
            if (j == i) continue;
            uf.unite(a[j], b[j]);
        }

        for (int i = 0; i < n; ++i) {
            if (uf.par[i] == -1) temp++;
        }

        if (temp > 1) ans++;
    }

    cout << ans << endl;
}
