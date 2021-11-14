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

typedef pair<int ,pair<int, int> > Edge;

int main()
{
    int n;
    cin >> n;

    UnionFind uf;
    uf.init(n);

    vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            if (a == -1) continue;
            edges.push_back(Edge(a,make_pair(i, j)));
        }
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
    return 0;
}