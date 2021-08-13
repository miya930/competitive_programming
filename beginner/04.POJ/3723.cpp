#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int> > Edge;

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

UnionFind uf;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m, r;
        cin >> n >> m >> r;

        vector<Edge> edges;
        uf.init(n+m);

        for (int i = 0; i < r; ++i) {
            int x, y;
            ll w;
            cin >> x >> y >> w;
            edges.push_back(Edge(w, make_pair(x, y+n)));
        }

        sort(edges.rbegin(), edges.rend());

        ll sum = 0;

        for (int i = 0; i < r; ++i) {

            ll w = edges[i].first;
            int x = edges[i].second.first;
            int y = edges[i].second.second;

            if (uf.issame(x, y)) continue;

            sum += w;

            uf.unite(x, y);
        }
    
        cout << 10000LL*(n+m) - sum << endl;
    }

    return 0;
}
