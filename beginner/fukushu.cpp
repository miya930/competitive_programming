#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> siz, par;

    // ������
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    // �������߂�
    int root (int x) {
        if (par[x] == -1) return x; // x�����̏ꍇ��x��Ԃ�
        else return par[x] = root(par[x]);
    }

    // x �� y�������O���[�v�ɑ����邩�ǂ���
    bool issame (int x, int y) {
        return root(x) == root(y);
    }

    // x ���܂ރO���[�v�� y ���܂ރO���[�v�Ƃ𕹍�����
    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        // union by size
        if (siz[x] < siz[y]) swap(x, y);

        // y �� x �̎q�Ƃ���
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x ���܂ރO���[�v�̃T�C�Y
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
