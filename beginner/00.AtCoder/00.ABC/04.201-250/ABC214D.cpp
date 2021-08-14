#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

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

typedef pair<long long, pair<int, int> > Edge;

int main()
{
    int n;
    cin >> n;
    
    vector<Edge> edges(n-1);
    UnionFind uf;
    uf.init(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    sort(edges.begin(), edges.end());

    long long ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ll w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        ans += (ll)uf.size(u)*(ll)uf.size(v)*w;

        uf.unite(u, v);
    }
    cout << ans << endl;
}
