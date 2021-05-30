#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, -1) { }

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

void query1(int px, int py);
bool query2(int px, int py, int qx, int qy);

int h, w, q;
bool used[2000][2000];

int main()
{
    cin >> h >> w >> q;

    UnionFind uf(h*w);

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

void query1(int px, int py) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
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
    int hash2 = (qx - 1) * w + (py - 1);
    return uf.issame(hash1, hash2);
}
