#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

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

UnionFind uf;
int n, m;
ll k;
ll ans = infl;
void func(UnionFind u, vector<pair<ll,pair<int,int>>> &v, int nex, int cnt, ll sum) {

    if (cnt >= n-1) {
        ans = min(ans, sum%k);
        return;
    }

    rep(i, nex+1, m) {
        ll w = v[i].first;
        int s = v[i].second.first;
        int t = v[i].second.second;
        UnionFind nu = u;

        if (nu.issame(s, t)) continue;
        nu.unite(s, t);
        func(nu, v, i, cnt+1, sum+w);
    }
}

int main()
{

    cin >> n >> m >> k;
    vector<pair<ll,pair<int,int>>> e;
    uf.init(n);
    rep(i, 0, m) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        e.push_back(make_pair(w, make_pair(u, v)));
    }

    func(uf, e, -1, 0, 0);
    cout << ans << endl;
    return 0;
}
