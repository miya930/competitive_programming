#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    // ������
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    // �������߂�
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]); 
    }

    // x �� y �������O���[�v�ɑ����邩�ǂ��� (������v���邩�ǂ���)
    
}

int main()
{

}
