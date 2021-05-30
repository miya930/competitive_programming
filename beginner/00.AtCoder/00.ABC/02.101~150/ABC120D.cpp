#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> siz, par;

    UnionFind(int n) : par(n, -1), siz(n, 1) { }

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
        return 0;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

long long ans[100100];

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> a(m), b(m);
    UnionFind uf(n);

    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    } 

    ans[m-1] = n * (n-1) / 2;

    for (int i = m-1; i > 0; --i) {
        if (uf.root(a[i]) == uf.root(b[i])) ans[i-1] = ans[i];
        else {
            ans[i-1] = ans[i] - uf.size(a[i]) * uf.size(b[i]);
            if (ans[i-1] < 0) ans[i-1] = 0;
            uf.unite(a[i], b[i]);
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }

}
