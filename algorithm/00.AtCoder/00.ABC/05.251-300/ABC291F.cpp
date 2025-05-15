#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const int inf = 1001001001;

vector<int> distn, distr;

template<class T> void bfs(vector<vector<int>> &G, int x, vector<T> &dist) {
    queue<int> que;
    dist[x] = 0;
    que.push(x);

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto nv : G[v]) {
            if (dist[nv] != inf) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n), GR(n);
    distn.assign(n, inf); distr.assign(n, inf);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                G[i].push_back(i+j+1);
                GR[i+j+1].push_back(i);
            }
        }
    }

    distn[0] = 0;
    distr[n-1] = 0;
    bfs(G, 0, distn);
    bfs(GR, n-1, distr);

    for (int k = 1; k < n-1; k++) {
        vector<pair<int,int>> pa;
        for (int j = max(0, k-(m-1)); j <= k-1; j++) {
            for (auto nv : G[j]) {
                if (nv >= k+1) {
                    pa.push_back(make_pair(j, nv));
                }
            }
        }
        int ans = inf;
        for (int j = 0; j < pa.size(); j++) {
            int u = pa[j].first;
            int v = pa[j].second;
            ans = min(ans, distn[u]+distr[v]+1);
        }
        if (ans == inf) cout << -1 << " ";
        else cout << ans << " ";
    }
    cout << endl;

    return 0;
}
