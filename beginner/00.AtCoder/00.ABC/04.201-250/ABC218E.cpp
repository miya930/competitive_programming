#include <iostream>
#include <vector>
#include <algorithm>
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
};

int n, m;
UnionFind uf;
vector<pair<ll, pair<int, int> > > vec;

int main()
{
    cin >> n >> m;
    uf.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        vec.push_back(make_pair(c, make_pair(a, b)));
    }

    sort(vec.begin(), vec.end());

    vector<int> index;
    ll ans = 0;
    for (int i = 0; i < (int)vec.size(); ++i) {
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        ll c = vec[i].first;

        if (uf.issame(a, b) || a == b) {
            if (c > 0) ans += c;
        }

        uf.unite(a, b);
    }

    cout << ans << endl;

}