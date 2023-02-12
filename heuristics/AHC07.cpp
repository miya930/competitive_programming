#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct vertex {
    int x;
    int y;
};

struct edge {
    int u;
    int v;
    ll w;
};

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

const int N = 400, M = 1995;
vector<vertex> pos(N);
vector<edge> e(M);
UnionFind uf;

void input(istream& is) {

    for (int i = 0; i < N; i++) {
        is >> pos[i].x >> pos[i].y;
    }
    
    for (int i = 0; i < M; i++) {
        is >> e[i].u >> e[i].v;

        ll ux = pos[e[i].u].x;
        ll uy = pos[e[i].u].y;
        ll vx = pos[e[i].v].x;
        ll vy = pos[e[i].v].y;

        e[i].w = ((ux-vx)*(ux-vx)+(uy-vy)*(uy-vy));

    }

    uf.init(N);

}

void resolve(void) {
    for (int m = 0; m < M; m++) {
        ll d; cin >> d;

        int u = e[m].u;
        int v = e[m].v;

        if (uf.issame(u, v)) {
            cout << 0 << endl;
            cout << flush;
        }

        uf.unite(u, v);

        cout << 1  << endl;
        cout << flush;

    }
}

int main()
{
    input(cin);

    resolve();

    return 0;
}
