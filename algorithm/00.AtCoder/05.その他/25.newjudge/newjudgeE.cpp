#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int n, m;
    cin >> n >> m;
    uf.init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.unite(u, v);
    }

    int k;
    cin >> k;
    vector<pair<int,int>> v(k);
    map<pair<int,int>, int> mp;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[i] = make_pair(a, b);
        int ra = uf.root(a);
        int rb = uf.root(b);
        mp[make_pair(ra, rb)]++;
        mp[make_pair(rb, ra)]++;
    }

    int Q; cin >> Q;
    for (int qq = 0; qq < Q; qq++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        int rp = uf.root(p);
        int rq = uf.root(q);
        if (mp.count(make_pair(rp, rq)) > 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }


    return 0;
}
