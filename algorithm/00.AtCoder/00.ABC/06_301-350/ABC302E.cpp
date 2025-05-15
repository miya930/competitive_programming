#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<set<int>>;

int main()
{
    int n, Q;
    cin >> n >> Q;
    Graph G(n);

    int ans = n;
    for (int q = 0; q < Q; q++) {
        int t, u, v;
        cin >> t;
        
        if (t == 1) {
            cin >> u >> v;
            u--; v--;

            if (G[u].size() == 0) ans--;
            if (G[v].size() == 0) ans--;
            G[u].insert(v);
            G[v].insert(u);

        } else {
            cin >> u;
            u--;

            auto itr = G[u].begin();

            while(itr != G[u].end()) {
                int v = *itr;
                G[v].erase(u);
                if (G[v].size() == 0) ans++;
                itr++;
            }
            if (G[u].size() > 0) ans++;
            G[u].clear();
        }
        cout << ans << endl;
    }

    return 0;
}
