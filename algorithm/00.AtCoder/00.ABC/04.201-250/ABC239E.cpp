#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<vector<int>> values;
vector<bool> seen;
vector<int> x;

void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv);
        for (auto val : values[nv]) values[v].push_back(val);
    }
    sort(values[v].rbegin(), values[v].rend());
    values[v].resize(21);
}

int main()
{
    int n, Q;
    cin >> n >> Q;

    Graph G(n);
    values.resize(n);
    x.resize(n);
    seen.assign(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        values[i].push_back(x[i]);
    }

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G, 0);

    for (int i = 0; i < Q; ++i) {
        int v, k;
        cin >> v >> k;
        v--; k--;
        cout << values[v][k] << endl;
    }

    return 0;
}
