#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    void init(int sz) {
        par.resize(sz, -1);
        siz.resize(sz, -1);
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
};


int h, w, q;
bool used[2009][2009];
UnionFind uf;


void query1(int px, int py) {
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    for (int i = 0; i < 4; ++i) {
        int sx = px + dx[i];
        int sy = py + dy[i];
        if (used[sx][sy] == false) continue;
        int hash1 = (px - 1) * w + (py - 1);
        int hash2 = (sx - 1) * w + (sy - 1);
        uf.unite(hash1, hash2);
    }
    used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
    if (used[px][py] == false || used[qx][qy] == false) {
        return false;
    }

    int hash1 = (px - 1) * w + (py - 1);
    int hash2 = (qx - 1) * w + (qy - 1);
    return uf.issame(hash1, hash2);
}

int main()
{
    cin >> h >> w >> q;

    uf.init(h * w);

    for (int i = 1; i <= q; ++i) {
        int ty; cin >> ty;
        if (ty == 1) {
            int x, y;
            cin >> x >> y;
            query1(x, y);
        }
        if (ty == 2) {
            int xa, xb, ya, yb;
            cin >> xa >> ya >> xb >> yb;
            bool answer = query2(xa, ya, xb, yb);
            if (answer == true) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}


/*** 2022.3.13 復習 ***/


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

int h, w, Q;
UnionFind uf;
vector<vector<bool>> painted;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void query1(int r, int c) {
    int tmp = r*w + c;
    painted[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        
        int ntmp = nx*w + ny;
        if (painted[nx][ny]) uf.unite(tmp, ntmp);
    }
}

bool query2(int r1, int r2, int c1, int c2) {
    int tmp1 = r1*w + c1;
    int tmp2 = r2*w + c2;

    if (uf.issame(tmp1, tmp2) && painted[r1][c1] && painted[r2][c2]) return true;
    else return false;
}

int main()
{
    cin >> h >> w >> Q;
    int n = h*w;

    painted.assign(h ,vector<bool>(w, false));
    uf.init(n);

    for (int q = 0; q < Q; ++q) {
        int t; cin >> t;
        
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--; c--;

            query1(r, c);

        } else if (t == 2) {
            int r1, r2, c1, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; r2--; c1--; c2--;

            if (query2(r1, r2, c1, c2)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
