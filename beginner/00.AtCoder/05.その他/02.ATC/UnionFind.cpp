#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

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

        if (siz[x] <= siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> p(q), a(q), b(q);
    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int p, a, b;
        cin >> p >> a >> b;
        if (p == 0) {
            uf.unite(a, b);
        }
        if (p == 1) {
            if (uf.issame(a, b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
