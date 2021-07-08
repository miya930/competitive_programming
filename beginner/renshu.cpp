#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > Graph;
vector<int> subtree_size;
vector<int> depth;

void dfs(const Graph &G, int v, int p, int d) {
    depth[v] = d;
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(G, nv, v, d+1);
    }

    subtree_size[v] = 1;
    for (auto c : G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c];
    }

}

int main()
{
    int n; cin >> n;

    Graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int root = 0;
    depth.assign(n, 0);
    subtree_size.assign(n, 0);
    dfs(G, root, -1);

    for (int v = 0; v < n; ++v) {
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
    }

}
