#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> siz, par;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

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

typedef pair<int, pair<int, int> > Edge; // 辺 e = (u, v) を {w(e), {u, v}} で表す。

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = Edge(w, make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    // クラスカル法
    long long res = 0;
    UnionFind uf(n);

    for (int i = 0; i < n; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (uf.issame(x, y)) continue;

        res += w;
        uf.unite(u, v);
    } 

    cout << res << endl;
}
