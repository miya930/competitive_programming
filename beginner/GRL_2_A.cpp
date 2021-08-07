#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int> > Edge;

struct UnionFind {
    int par, siz;

    void init(int n) {
        par.resize(n, -1);
        siz.resize(n, 1);
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
        return root(x);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(n);

    

}
