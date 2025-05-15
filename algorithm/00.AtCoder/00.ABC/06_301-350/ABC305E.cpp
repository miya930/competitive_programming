#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> guard(n, false);
    vector<bool> seen(n, false);
    vector<int> p(n), h(n);
    vector<int> pow(n, 0);
    priority_queue<P> que;
    for (int i = 0; i < k; i++) {
        cin >> p[i] >> h[i];
        p[i]--;
        guard[p[i]] = true;
        que.push(make_pair(h[i], p[i]));
        pow[p[i]] = h[i];
    }

    seen[que.top().second] = true;
    while(!que.empty()) {
        int v = que.top().second;
        int c = que.top().first;
        que.pop();
        if (c < pow[v]) continue;

        for (auto nv : G[v]) {
            if (seen[nv]) continue;
            int nc = c - 1;
            if (pow[nv] < nc) que.push(make_pair(nc, nv));
            seen[nv] = true;
            guard[nv] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (guard[i]) cnt++;
    }
    cout << cnt++ << endl;
    for (int i = 0; i < n; i++) {
        if (guard[i]) cout << i + 1 << ' ';
    }
    cout << endl;

    return 0;
}
