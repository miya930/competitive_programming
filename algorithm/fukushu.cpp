#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> color;
map<pair<int,int>, int> mp;

void dfs(const Graph &G, int v, int co) {
    seen[v] = true;

    int cnt = 1;
    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;

        if (cnt == co) cnt++;
        dfs(G, nv, cnt);
        int v1 = v;
        int v2 = nv;
        if (v > nv) swap(v1, v2);
        int num = mp[make_pair(v1, v2)];
        color[num] = cnt;
        cnt++;
    }
}

int main()
{
    int n;
    cin >> n;

    Graph G(n);
    seen.resize(n);
    color.resize(n-1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        mp[make_pair(a, b)] = i;
    }

    dfs(G, 0, 0);

    int k = 0;
    for (int i = 0; i < n-1; ++i) {
        if (k < color[i]) k = color[i];
    }
    cout << k << endl;
    for (int i = 0; i < n-1; ++i) cout << color[i] << endl;

    return 0;
}
