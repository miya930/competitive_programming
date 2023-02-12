// 最小全域木を1個作って、その辺だけを抽出するアプローチ
#include <bits/stdc++.h>
#define debug (1)
using namespace std;
using ll = long long;
using Edge = vector<pair<int,int>>;
using Graph = vector<vector<int>>;
using Edgelen = vector<pair<double, pair<int,int>>>;

const int n = 400;
const int m = 1995;

#if debug

    string output_csv_path = "test.csv";
    ofstream ofs_csv_file(output_csv_path);

#endif

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

int main()
{
    Edge e(m);
    Graph G(n);
    Edgelen edgelen;
    UnionFind uf;
    uf.init(n);
    vector<pair<int,int>> pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[i].first = u;
        e[i].second = v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int v = 0; v < n; ++v) {
        for (int nv = v+1; nv < n; ++nv) {
            int vx = pos[v].first;
            int vy = pos[v].second;
            int nx = pos[nv].first;
            int ny = pos[nv].second;
            double d = sqrt((nx-vx)*(nx-vx)+(ny-vy)*(ny-vy));
            edgelen.push_back(make_pair(d, make_pair(v, nv)));
        }
    }

    // 最小全域木
    sort(edgelen.begin(), edgelen.end());
    vector<pair<int,int>> list;
    int size = edgelen.size();
    for (int i = 0; i < size; ++i) {
        double d = edgelen[i].first;
        int v  = edgelen[i].second.first;
        int nv = edgelen[i].second.second;

        if (!uf.issame(v, nv)) {
            uf.unite(v, nv);
            list.push_back(make_pair(v, nv));
        }
    }

    int listsize = list.size();

    uf.init(n);
    for (int i = 0; i < m; ++i) {
        int weight; cin >> weight;
        bool ans = 0;

        int x = e[i].first;
        int y = e[i].second;

        if (x > y) swap(x, y);

        for (int j = 0; j < listsize; ++j) {
            int v = list[j].first;
            int nv = list[j].second;
            if (x == v && y == nv && !uf.issame(v, nv)) {
                ans = true;
                uf.unite(x, y);
            }
        }

#if debug
        
        ofs_csv_file << ans << "\n";

#endif

        cout << ans << endl;
        cout << flush;
    }


    return 0;
}
