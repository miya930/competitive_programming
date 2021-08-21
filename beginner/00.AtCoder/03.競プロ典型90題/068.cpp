#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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
};

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<ll> T(Q), X(Q), Y(Q), V(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
        X[i]--; Y[i]--;
    }

    vector<int> sum(n-1, 0);
    for (int i = 0; i < Q; ++i) {
        if (T[i] == 0) {
            sum[X[i]] = V[i];
        }
    }
    vector<ll> potential(n, 0);
    for (int i = 0; i < n-1; ++i) {
        potential[i+1] = sum[i] - potential[i];
    }
    UnionFind uf;
    uf.init(n);

    for (int i = 0; i < Q; ++i) {
        if (T[i] == 0) {
            uf.unite(X[i], Y[i]);
        } else if (T[i] == 1) {
            if (!uf.issame(X[i], Y[i])) cout << "Ambiguous" << endl;
            else if ((X[i]+Y[i])%2 == 0) {
                cout << V[i] + (potential[Y[i]] - potential[X[i]]) << endl;
            } else {
                cout << (potential[X[i]] - V[i]) + potential[Y[i]] << endl;
            }
        }
    } 
    return 0;
}

