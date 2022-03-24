#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;

vector<bool> seen;
vector<int> post_order;
long long cnt = 0;

void dfs_1(const Graph& G, int v) {
    seen[v] = true;

    for (int nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs_1(G, nv);
    }
    post_order.push_back(v);
}

void dfs_2(const Graph& G, int v) {
    seen[v] = true;
    cnt++;
    for (int nv : G[v]) {
        if (seen[nv] == true) continue;
        dfs_2(G, nv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    seen.assign(n, false);

    Graph G_1(n), G_2(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G_1[a].push_back(b);
        G_2[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (seen[i] != true) dfs_1(G_1, i);
    }

    long long ans = 0;
    reverse(post_order.begin(), post_order.end());
    seen.assign(n, false);
    for (int i : post_order) {
        if (seen[i] == true) continue;
        cnt = 0;
        dfs_2(G_2, i);
        ans += cnt * (cnt - 1LL) / 2LL;
    }

    cout << ans << endl;
}


/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<int> tsort;
vector<bool> seen;
ll cnt = 0;

void dfs1(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;
        dfs1(G, nv);
    }

    tsort.push_back(v);
}

void dfs2(const Graph &G, int v) {
    seen[v] = true;
    cnt++;

    for (auto nv : G[v]) {
        if (seen[nv] != false) continue;
        dfs2(G, nv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    seen.assign(n, false);
    Graph G1(n), G2(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G1[a].push_back(b);
        G2[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (seen[i] == true) continue;
        dfs1(G1, i);
    }

    ll ans = 0;
    reverse(tsort.begin(), tsort.end());
    seen.assign(n, false);
        
    for (int i = 0; i < n; ++i) {
        int v = tsort[i];
        if (seen[v] == true) continue;
        cnt = 0;
        dfs2(G2, v);
        ans += cnt*(cnt-1LL)/2LL;
    }

    cout << ans << endl;
    return 0;
}
