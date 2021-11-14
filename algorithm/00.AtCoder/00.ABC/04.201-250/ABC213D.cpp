#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> seen;
vector<int> ans;
typedef vector<vector<int> > Graph;

void dfs(const Graph& G, int v) {
    seen[v] = true;
    ans.push_back(v);

    for (auto nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs(G, nv);
        ans.push_back(v);
    }
}

int main()
{
    int n;
    cin >> n;
    seen.assign(n, false);

    Graph G(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) sort(G[i].begin(), G[i].end());

    dfs(G, 0);

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
