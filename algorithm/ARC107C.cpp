#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

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
    int n, k;
    cin >> n >> k;
    UnionFind uf1, uf2;
    uf1.init(n); uf2.init(n);

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    ll cnt1 = 1, cnt2 = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool flag = true;
            for (int l = 0; l < n; ++l) {
                int tmp = a[i][l] + a[j][l];
                if (tmp > k) flag = false;
            }
            if (flag) uf1.unite(i, j);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool flag = true;
            for (int l = 0; l < n; ++l) {
                int tmp = a[l][i] + a[l][j];
                if (tmp > k) flag = false;
            }
            if (flag) uf2.unite(i, j);
        }
    }

    ll tmp1 = 1, tmp2 = 1;
    for (ll i = 1; i <= cnt1; i++) {
        tmp1 *=i;
        tmp1 %= mod;
    }
    for (ll i = 1; i <= cnt2; i++) {
        tmp2 *= i;
        tmp2 %= mod;
    }
    
    cout << tmp1 * tmp2 % mod << endl;

    return 0;
}
