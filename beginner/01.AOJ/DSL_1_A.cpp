#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    void init(int n) {
        par.assign(n, -1);
        siz.assign(n, 1);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        else par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y){
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
    int n, Q;
    cin >> n >> Q;

    UnionFind uf;
    uf.init(n);

    for (int q = 0; q < Q; ++q) {
        int com, x, y;
        cin >> com >> x >> y;

        if (!com) {
            uf.unite(x, y);
        } else {
            cout << (int)uf.issame(x, y);
            cout << "\n";
        }
    }

    return 0;
}
