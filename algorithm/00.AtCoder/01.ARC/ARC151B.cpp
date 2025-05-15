#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 998244353;

vector<bool> seen;

void dfs(Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        dfs(G, nv);
    }
}

template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

template <class T> T moddiv(T n, T mo) {
    return modpow(n, mo-2, mo);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    Graph G(n);
    seen.assign(n ,false);
    for (int i = 0;i < n; i++) {
        int p;
        cin >> p;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
    }

    ll c = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        dfs(G, i);

        c++;
    }

    ll ans = modpow(m, n, mod);
    ans -= modpow(m, c, mod);

    ans = (ans + 2*mod) % mod;

    cout << ans * moddiv(2LL, mod) % mod << endl;

    return 0;
}
