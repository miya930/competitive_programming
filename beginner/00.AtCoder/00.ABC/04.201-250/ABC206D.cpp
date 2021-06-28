#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind {
    vector<int> siz, par;

    void init(int sz) {
        par.resize(sz, -1);
        siz.resize(sz, 1);
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

int n;
UnionFind uf;

int main()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    uf.init(200100);

    long long ans = 0;
    for (int i = 0; i < (int)a.size()/2; ++i) {
        if (a[i] != a[n-i-1]) {
            if(uf.root(a[i]) != uf.root(a[n-i-1])) {
                uf.unite(a[i], a[n-i-1]);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;

}
