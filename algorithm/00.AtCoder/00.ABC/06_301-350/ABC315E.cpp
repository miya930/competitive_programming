#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> topo;

void dfs(Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        dfs(G, nv);
    }

    topo.push_back(v);
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    seen.assign(n, false);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            p--;
            G[i].push_back(p);
        }
    }

    dfs(G, 0);

    for (int i = 0; i < topo.size()-1; i++) cout << topo[i] + 1 << " ";
    cout << endl;

    return 0;
}
