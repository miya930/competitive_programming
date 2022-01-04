#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<int> color;
bool flag = true;

void dfs(const Graph &G, int v, int c) {
    color[v] = c;

    for (auto nv : G[v]) {
        if (color[nv] == c) flag = false;
        if (color[nv] != -1) continue;

        dfs(G, nv, 3-c);
    }
}

int main()
{
    int n ,m;
    cin >> n >> m;
    Graph G(n);
    color.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (color[i] != -1) continue;
        dfs(G, i, 1);
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
