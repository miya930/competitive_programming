#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    vector<int> vec(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[v].push_back(u);
        vec[u]++;
    }

    queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (vec[i] == 0) que.push(i);
    }

    int ans = n;
    while(!que.empty()) {
        ans--;
        int v = que.front();
        que.pop();
        
        for (auto nv : G[v]) {
            vec[nv]--;
            if (vec[nv] == 0) {
                que.push(nv);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
