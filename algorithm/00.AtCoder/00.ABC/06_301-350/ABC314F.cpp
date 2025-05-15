#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

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

struct Edge {
    int to;
    mint pro;
    Edge(int to, mint pro): to(to), pro(pro) {}
};

using Graph = vector<vector<Edge>>;
UnionFind uf;
vector<mint> dp(400010, 0);
vector<bool> seen(400010);

int main()
{
    int n;
    cin >> n;
    Graph G(2*n);
    uf.init(2*n);
    vector<int> p(n-1), q(n-1);
    map<int,int> top;
    vector<int> child(2*n, 0);
    
    int add = n;
    for (int i = 0; i < n; i++) {
        top[i] = i;
        child[i] = 1;
    }

    for (int i = 0; i < n-1; i++) {
        cin >> p[i] >> q[i];
        p[i]--; q[i]--;

        int rp = uf.root(p[i]);
        int rq = uf.root(q[i]);

        int vp = top[rp];
        int vq = top[rq];

        int szp = child[vp];
        int szq = child[vq];
        
        G[add].push_back(Edge(vp, (mint)szp / (szp + szq)));
        G[vp].push_back(Edge(add, (mint)szp / (szp + szq)));
        G[add].push_back(Edge(vq, (mint)szq / (szp + szq)));
        G[vq].push_back(Edge(add, (mint)szq / (szp + szq)));

        uf.unite(vp, add);
        uf.unite(vq, add);

        top[rp] = add;
        top[rq] = add;

        child[add] = child[vp] + child[vq];

        add++;
    }

    queue<int> que;
    que.push(add-1);
    seen[add-1] = true;
    
    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (seen[nv.to]) continue;

            dp[nv.to] += (dp[v] + nv.pro);
            seen[nv.to] = true;
            que.push(nv.to);
        }
    }

    for (int i = 0; i < n; i++) cout << dp[i].val() << " ";
    cout << endl;

    return 0;
}
