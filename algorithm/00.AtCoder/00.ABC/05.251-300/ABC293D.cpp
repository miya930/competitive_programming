#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), c(m);
    vector<char> b(m), d(m);
    vector<int> deg(n+1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; c[i]--;
        deg[a[i]]++;
        deg[c[i]]++;
    }

    Graph G(n);
    for (int i = 0; i < m; i++) {
        int u = a[i];
        int v = c[i];

        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> seen(n, false);

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++) {
        if (seen[i] == true) continue;

        bool iscycle = true;
        seen[i] = true;
        queue<int> que;
        que.push(i);

        while(!que.empty()) {
            int v = que.front();
            que.pop();

            if (deg[v] != 2) iscycle = false;

            for (auto nv : G[v]) {
                if (seen[nv]) continue;

                que.push(nv);
                seen[nv] =true;
            }
        }

        if (iscycle) ans1++;
        else ans2++;

    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}
