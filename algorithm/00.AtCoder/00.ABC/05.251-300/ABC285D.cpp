#include <bits/stdc++.h>
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

    int size(int x) {
        return siz[root(x)];
    }

};

int main()
{
    int n;
    cin >> n;

    vector<string> s(n), t(n);
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i];

    map<string, int> mp;
    UnionFind uf;
    uf.init(2*n+1);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        if (mp.count(s[i]) == 0) {
            mp[s[i]] = cur;
            cur++;
        }
        if (mp.count(t[i]) == 0) {
            mp[t[i]] = cur;
            cur++;
        }

        int t1 = mp[s[i]];
        int t2 = mp[t[i]];
        if (uf.issame(t1, t2)) {
            cout << "No" << endl;
            return 0;
        } else {
            uf.unite(t1, t2);
        }
    }
    
    cout << "Yes" << endl;

    return 0;
}
