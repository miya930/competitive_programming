#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;

// トポロジカルソートする
vector<bool> seen;
vector<int> order; // トポロジカルソート順を表す
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }

    // v-out を記録する. (抜けた順に配列に記録される)
    order.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n); // 頂点数と辺数
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(n, false); // 初期状態では全頂点が未訪問
    order.clear(); // トポロジカルソート順
    for (int v = 0; v < n; ++v) {
        if (seen[v]) continue;
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 逆順に

    // 出力
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}
