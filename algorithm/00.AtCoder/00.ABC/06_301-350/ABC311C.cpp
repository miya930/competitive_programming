#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> vis;
bool exist = false;
int last = 0;

void dfs(Graph &g, int v) {
    seen[v] = true;

    for (auto nv : g[v]) {
        if (seen[nv]) {
            vis[nv] = v;
            last = nv;
            exist = true;
            continue;
        }

        vis[nv] = v;

        dfs(g, nv);
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    seen.assign(n, false);
    vis.assign(n, -1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a--;
        G[i].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (seen[i]) continue;
        if (exist) break;
        dfs(G, 0);
    }

    int cur = last;
    vector<int> ans;
    while(1) {
        if (ans.size() > 0 && cur == last) {
            break;
        }
        ans.push_back(cur);
        cur = vis[cur];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
