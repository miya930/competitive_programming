#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;     // v を訪問済みにする.

    // v からいける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済みなら探索しない.
        dfs(G, next_v);
    }
}

int main()
{
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ入力受取 (ここでは有向グラフを想定)
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(n, false);
    for (int v = 0; v < n; ++i) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}
