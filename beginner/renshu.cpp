#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int> > Edge;

struct UnionFind{
    vector<int> par, siz;

    UnionFind(int n): par(n, -1), siz(n, 1) {}

    root(int x) {
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

    vector<Edge> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    long long res = 0;
    UnionFind uf(n);

    for (int i = 0;i < m; ++i) {
        int v = edges[i].second.first;
        int u = edges[i].second.second;
        int w = edges[i].first;

        if (uf.issame(v, u)) continue;

        uf.unite(u, v);
        res += w;
    }

}
