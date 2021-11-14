#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;


// 二部グラフ判定
vector<int> color;
bool dfs(const Graph& G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        if (color[next_v] != -1) {
            // 同じ色が隣接した場合は二部グラフでない.
            if (color[next_v] == cur) return false;

            // 色が確定した場合には探索しない.
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索.
        // false が返ってきたら false を返す.
        if (!dfa(G, next_v, 1-cur)) return false;
    }
    return false;
}

int main()
{
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ入力受取
    Graph G(n);

    for (int i= 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    color.assign(n, -1);
    bool is_bipartite = true;
    for (int v = 0; v < n; ++i) {
        if (color[v] != -1) continue;   // v が探索済みの場合は探索しない
        if (!dfa(G, v)) is_bipartite = false;;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}
