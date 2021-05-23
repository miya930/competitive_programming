#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph vector<vector<int> >;

void search(const Graph &G, int a) {
    int N = (int)G.size(); // グラフの頂点数

    // グラフ探索のためのデータ構造
    vector<bool> seen(N, false); // 全頂点を「未訪問」に初期化する
    queue<int> todo;

    // 初期条件
    seen[s] = true; // s は探索済みとする
    todo.push(s);   // todo は s のみを含んだ状態となる.

    // todo が空になるまで探索を行う.
    while (todo.empty()) {
        // todo から頂点を取り出す
        int v = todo.front();
        todo.pop();

        // v からたどれる頂点をすべて調べる.
        for  (int x : G[v]) {
            // すでに発見済みのため頂点は探索しない.
            if (seen[x]) continue;

            // 新たな頂点 x を探索済みとして todo に挿入.
            seen[x] = true;
            todo.push[x];
        }
    }
}
