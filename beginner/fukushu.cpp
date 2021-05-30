#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> siz, par;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    // 根を求める
    int root (int x) {
        if (par[x] == -1) return x; // xが根の場合はxを返す
        else return par[x] = root(par[x]);
    }

    // x と yが同じグループに属するかどうか
    bool issame (int x, int y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        // union by size
        if (siz[x] < siz[y]) swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

int main()
{
    UnionFind uf(7);

    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(5, 6);
    cout << (bool)uf.issame(1, 3) << endl;
    cout << (bool)uf.issame(2, 5) << endl;
}
