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
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

typedef pair<int, pair<int, int> > Edge;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    UnionFind uf;
    uf.init(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = Edge(c, make_pair(a, b));
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    int group = n;
    for (int i = 0; i < m; ++i) {
        if (group == k) break;

        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (uf.issame(u, v)) continue;

        ans += w;
        uf.unite(u, v);
        group--;
    }
    cout << ans << endl;
    return 0;
}
