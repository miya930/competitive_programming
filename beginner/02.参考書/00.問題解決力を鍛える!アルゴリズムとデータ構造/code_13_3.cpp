#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int> >;

// 入力：グラフGと、探索の始点 s
// 出力：s から各頂点への最短路長を表す配列
vector<int> BFS(const Graph& graph, int s) {
    int N = (int)G.size(); // 頂点数
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期頂点とする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点とする.

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す.
        que.pop();

        // v からたどれる頂点をすべて調べる.
        for (int x : G[v]) {
            // すでに発見済みの頂点は探索しない
            if (dist[x] != -1) continue;

            // 新たな白色頂点 x について距離情報を更新してキューに挿入
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main()
{
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 を始点とした BFS
    vector<int> dist = BFS(G, 0);

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < n; ++v) cout << v << ": " << dist[v] << endl;
}
