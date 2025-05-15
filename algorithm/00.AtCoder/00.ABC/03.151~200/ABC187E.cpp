#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<int> depth;
vector<bool> seen;
vector<ll> s;

void dfs(Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        depth[nv] = depth[v] + 1;
        dfs(G, nv);
    }
}

void dfs2(Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        s[nv] += s[v];
        dfs2(G, nv);
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    depth.assign(n, -1);
    seen.assign(n, false);
    vector<pair<int,int>> edge(n-1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edge[i] = make_pair(a, b);
    }

    depth[0] = 0;
    dfs(G, 0);

    int Q;
    cin >> Q;
    s.resize(n);
    while(Q--) {
        int t, e, x;
        cin >> t >> e >> x;
        e--;

        int a = edge[e].first;
        int b = edge[e].second;

        if (depth[a] > depth[b]) {
            swap(a, b);
            if (t == 1) t = 2;
            else t = 1;
        }

        if (t == 1) {
            s[0] += x;
            s[b] -= x;
        } else {
            s[b] += x;
        }
    }

    seen.assign(n, false);
    dfs2(G, 0);

    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}
