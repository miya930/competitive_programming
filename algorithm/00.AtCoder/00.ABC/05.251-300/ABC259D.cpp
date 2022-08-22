#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct circle {
    ll x;
    ll y;
    ll r;
};

int sidx, tidx;

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
    int n;
    ll sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;

    vector<circle> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i].x >> vec[i].y >> vec[i].r;

    UnionFind uf;
    uf.init(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (i == j) continue;
            ll x1 = vec[i].x, x2 = vec[j].x;
            ll y1 = vec[i].y, y2 = vec[j].y;
            ll r1 = vec[i].r, r2 = vec[j].r;

            ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            ll rr   = r1*r1 + 2*r1*r2 + r2*r2;
            ll rrr  = r1*r1 - 2*r1*r2 + r2*r2;

            if (dist <= rr && (dist >= rrr)) {
                uf.unite(i, j);
            } 
        }
    }

    for (int i = 0; i < n; ++i) {
        ll s1 = (sx - vec[i].x)*(sx - vec[i].x) + (sy - vec[i].y)*(sy - vec[i].y);
        ll t1 = (tx - vec[i].x)*(tx - vec[i].x) + (ty - vec[i].y)*(ty - vec[i].y);

        if (s1 == vec[i].r*vec[i].r) {
            sidx = i;
        }
        if (t1 == vec[i].r*vec[i].r) {
            tidx = i;
        }
    }

    if (uf.issame(sidx, tidx)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
