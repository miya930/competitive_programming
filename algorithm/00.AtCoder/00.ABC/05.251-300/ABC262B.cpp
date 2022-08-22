#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n ,m;
    cin >> n >> m;

    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool found = false;
            for (auto x : G[i]) {
                if (x == j) {
                    found = true;
                    break;
                }
            }

            if (found == false) continue;

            for (int k = j + 1; k < n ; ++k) {
                bool found2 = false, found3 = false;
                for (auto x : G[k]) {
                    if (x == i) found2 = true;
                    else if (x == j) found3 = true;
                }
                if (found2 == true && found3 == true) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
