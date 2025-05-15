#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    int n, s, t;
    cin >> n >> s >> t;
    s--; t--;
    Graph G(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G{v}.push_back(u);
    }

    queue<int> que;
    vector<bool> seen(n, false);
    vector<vector<int>> sg(n), tg(n);

    seen[s]

    return 0;
}
