#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int> >;

vector<bool> seen;
void dfa(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        dfa(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数、s と t
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    // グラフ入力受取
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 頂点 a をスタートとした探索
    seen.assign(n, false); // 全頂点を「未訪問」に初期化
    dfa(G, a);

    // t にたどり着けるか
    if (seen[t]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
