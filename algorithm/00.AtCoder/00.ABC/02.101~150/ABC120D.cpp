#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    vector<long long> ans;
    UnionFind uf;
    uf.init(n);

    long long pre = 1LL*n*(n-1)/2;
    ans.push_back(pre);

    for (int i = m-1; i > 0; --i) {
        long long siz_a = uf.size(a[i]), siz_b = uf.size(b[i]);
        if (uf.unite(a[i],b[i])) {
            pre -=  siz_a*siz_b;
            ans.push_back(pre);
        } else {
            ans.push_back(pre);
        }
    }
    
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << endl;
}
