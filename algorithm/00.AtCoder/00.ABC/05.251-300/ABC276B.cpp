#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;

    Graph G(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 0 ; i < n; ++i) {
        sort(G[i].begin(), G[i].end());
    }

    for (int i = 0; i < n; ++i) {
        cout << G[i].size() << " ";
        for (int j = 0;j < G[i].size(); ++j) {
            cout << G[i][j]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}
