#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll,int>;
const ll infl = 1LL << 60;

priority_queue<P, vector<P>, greater<P>> que;
vector<ll> a,c;
int n, m;

int main()
{
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Graph G(n);
    c.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        ll cost = 0;
        for (auto x : G[i]) {
            cost += a[x];
        }
        que.push(P(cost, i));
        c[i] = cost;
    }

    int count = 0;
    ll ans = -infl;
    vector<bool> removed(n, false);
    while(count < n) {
        ll val = que.top().first;
        int e = que.top().second;
        que.pop();

        if (removed[e]) continue;
        ans = max(ans, val);
        count++;
        removed[e] = true;
        
        for (auto x : G[e]) {
            c[x] -= a[e];
            que.push(P(c[x], x));
        }
    }

    cout << ans << endl;
    return 0;
}
