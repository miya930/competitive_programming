#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

struct Edge {
    int to;
    ll w;
    int idx;
};

using P = pair<ll,int>;
priority_queue<P, vector<P>, greater<P>> que;
vector<ll> dist, ans;
vector<int> pre;
UnionFind uf;

int main()
{
    int n ,m;
    cin >> n >> m;
    dist.assign(n, infl);
    pre.assign(n, -1);
    map<pair<int,int>,int> mp;

    vector<vector<Edge>> Graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(Edge{b, c, i+1});
        Graph[b].push_back(Edge{a, c, i+1});

        if (a > b) swap(a, b);
        mp[make_pair(a, b)] = i;
    }

    que.push(P(0, 0));
    dist[0] = 0;

    while(!que.empty()) {
        int v = que.top().second;
        ll w = que.top().first;
        que.pop();

        if (w > dist[v]) continue;

        for (auto e : Graph[v]) {
            if (dist[v]+e.w < dist[e.to]) {
                dist[e.to] = dist[v] + e.w;
                que.push(P(dist[e.to],e.to));
                pre[e.to] = v;
            }
        }
    }

    for (int i = n-1; i > 0; --i) {
        int u = i;
        int v = pre[i];
        if (u > v) swap(u, v);
        int idx = mp[make_pair(u, v)];
        ans.push_back(idx+1);
    }


    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
 