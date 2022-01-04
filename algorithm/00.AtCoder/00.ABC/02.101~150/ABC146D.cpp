#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int> color;
map<P, int> mp;

void dfs(const Graph &G, int v, int cur) {
    int cnt = 1;

    for (auto nv : G[v]) {
        int tmp1 = v, tmp2 = nv;
        if (v > nv) swap(tmp1, tmp2);

        if (color[mp[P(tmp1, tmp2)]] != -1) continue;
        if (cnt == cur) cnt++;

        color[mp[P(tmp1, tmp2)]] = cnt;
        dfs(G, nv, cnt);
        cnt++;
    }

}

int main()
{
    int n;
    cin >> n;
    
    color.assign(n-1, -1);
    Graph G(n);

    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        mp[P(a, b)] = i;
    }

    dfs(G, 0, -1);
    int k = 0;
    for (int i = 0; i < n-1; ++i) k = max(k, color[i]);
    cout << k << endl;

    for (int i = 0; i < n-1; ++i) cout << color[i] << endl;
    return 0;
}
