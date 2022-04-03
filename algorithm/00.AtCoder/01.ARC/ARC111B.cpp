#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<bool> seen;
bool flag = false;
const int N = 400100;
Graph G(N);

void dfs(const Graph &G, int v, int p, map<int,int> &mp) {
    seen[v] = true;
    if (mp[v] == 0) mp[v]++;

    for (auto nv : G[v]) {
        if (nv == p) continue;
        if (seen[nv] == true) {
            flag = true;
            continue;
        }

        dfs(G, nv, v, mp);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> vec;
    seen.assign(N, false);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vec.push_back(a); vec.push_back(b);
    }

    int ans = 0;
    for (int i = 0;i < (int)vec.size(); ++i) {
        if (seen[vec[i]] == true) continue;
        flag = false;
        map<int,int> vis;
        dfs(G, vec[i], vec[i], vis);
        if (flag || (G[vec[i]].size() != 1 && vis.size() == 1)) ans += vis.size();
        else ans += (vis.size()-1);
    }

    cout << ans << endl;
    return 0;
}
