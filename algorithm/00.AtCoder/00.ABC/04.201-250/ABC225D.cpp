#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
using Graph = vector<vector<int> > ;

vector<bool> seen;
void dfs(const Graph &G, int v, vector<int> &ans) {
    seen[v] = true;
    ans.push_back(v+1);

    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;

        dfs(G, nv, ans);
    }   
}

int main()
{
    int n, Q;
    cin >> n >> Q;

    vector<int> par(n, -1);
    Graph G(n);

    
    for (int q = 0; q < Q; ++q) {
        int t, x, y;
        cin >> t >> x;
        x--;
        if (t != 3) {
            cin >> y;
            y--;
        }

        if (t == 1) {
            G[x].push_back(y);
            par[y] = x;
        } else if (t == 2) {
            G[x].erase(G[x].begin());
            par[y] = -1;
        } else {
            int size = 0;
            seen.assign(n, false);

            int v = x;
            vector<int> ans;

            while (1) {
                if (par[v] == -1) break;
                else v = par[v];
            }

            dfs(G, v, ans);

            int m = ans.size();
            cout << m << " ";
            for (int i = 0; i < m; ++i) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
