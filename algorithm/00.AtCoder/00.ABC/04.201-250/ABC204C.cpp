#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef vector<vector<int> > Graph;

vector<bool> seen;
void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        seen.assign(n, false);
        dfs(G, i);
        for (int j = 0; j < n; ++j) {
            if (seen[j]) ans++;
        }
    }
    cout << ans << endl;
}
