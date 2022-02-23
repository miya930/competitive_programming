#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;

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

ll perm(ll x) {
    ll ret = 1;
    for (ll i = 2; i <= x; ++i) {
        ret *= i;
        ret %= mod;
    }
    return ret;
}

int main()
{
    int n, k;
    cin >> n >> k;

    UnionFind ufr, ufc;
    ufr.init(n); ufc.init(n);

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int x = 0; x < n; ++x) { // row1
        for (int y = x+1; y < n; ++y) { // row2
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                int sum = a[x][i] + a[y][i];
                if (sum > k) flag = false;
            }
            if (flag) ufr.unite(x, y);
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int y = x+1; y < n; ++y) {
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                int sum = a[i][x] + a[i][y];
                if (sum > k) flag = false;
            }
            if (flag) ufc.unite(x, y);
        }
    }

    vector<bool> seenr(n, false), seenc(n, false);
    ll row = 1, column = 1;
    for (int i = 0; i < n; ++i) {
        if (seenr[ufr.root(i)]) continue;
        row *= perm((ll)ufr.size(i));
        row %= mod;
        seenr[ufr.root(i)] = true;
    }

    for (int i = 0; i < n; ++i) {
        if (seenc[ufc.root(i)]) continue;
        column *= perm((ll)ufc.size(i));
        column %= mod;
        seenc[ufc.root(i)] = true;
    }

    cout << row * column % mod << endl;

    return 0;
}
