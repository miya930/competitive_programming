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
    int n;
    cin >> n;
    
    UnionFind uf;
    uf.init(n);
    
    vector<pair<int, int> > X, Y;
    vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    for (int i = 1; i < n; ++i) {
        int dx = abs(X[i].first - X[i-1].first);
        int dy = abs(Y[i].first - Y[i-1].first);
        int ux = X[i].second;
        int vx = X[i-1].second;
        int uy = Y[i].second;
        int vy = Y[i-1].second;
        edges.push_back(Edge(dx, make_pair(ux, vx)));
        edges.push_back(Edge(dy, make_pair(uy, vy)));
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    for (int i = 0; i < (int)edges.size(); ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (uf.issame(u, v)) continue;

        ans += w;
        uf.unite(u, v);
    }
    cout << ans << endl;

}
