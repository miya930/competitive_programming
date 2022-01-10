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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    UnionFind uf;
    uf.init(n);
    int v = 0;
    int ans = 0;
    int cnt = 0;

    while (1) {
        int nv = a[v];
        cnt++;
        if (uf.issame(v, nv)) {
            ans = -1;
            break;
        } else if (nv == 1) {
            ans = cnt;
            break;
        }

        uf.unite(v, nv);
        v = nv;
    }

    cout << ans << endl;
    return 0;
}
