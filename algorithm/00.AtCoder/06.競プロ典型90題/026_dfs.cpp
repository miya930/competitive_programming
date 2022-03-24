#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Graph;

vector<int> seen;

void dfs(const Graph& G, int v, int cur) {
    seen[v] = cur;

    for (int nv : G[v]) {
        if (seen[nv] >= 1) continue;
        dfs(G,nv, 3 - cur);
    }
}

int main()
{
    int n;
    cin >> n;
    seen.assign(n, -1);

    Graph G(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G, 0, 1);

    vector<int> G_1, G_2;
    for (int i = 0; i < n; ++i) {
        if (seen[i] == 1) G_1.push_back(i+1);
        else if (seen[i] == 2) G_2.push_back(i+1);
    }

    if (G_1.size() < G_2.size()) {
        for (int i = 0; i < n/2; ++i) {
            cout << G_2[i] << " ";
        }
    }
    else {
        for (int i = 0; i < n/2; ++i) {
            cout << G_1[i] << " ";
        }
    }
    cout << endl;
}


/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
vector<int> color;

void dfs(const Graph &G, int v, int c) {
    color[v] = c;

    for (auto nv : G[v]) {
        if (color[nv] != -1) continue;
        dfs(G, nv, 3-c);
    }
}

int main()
{
    int n;
    cin >> n;
    color.assign(n, -1);
    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(G, 0, 1);
    vector<int> ans1, ans2;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 1) ans1.push_back(i);
        if (color[i] == 2) ans2.push_back(i);
    }
    
    if (ans1.size() > ans2.size()) {
        for (int i = 0; i < min(n/2, (int)ans1.size()); ++i) cout << ans1[i]+1 << " ";
        cout << endl;
    } else {
        for (int i = 0; i < min(n/2,(int)ans2.size()); ++i) cout << ans2[i]+1 << " ";
    }

    return 0;
}
