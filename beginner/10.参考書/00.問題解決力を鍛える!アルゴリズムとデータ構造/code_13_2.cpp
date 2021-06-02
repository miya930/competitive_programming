#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

// [‚³—Dæ’Tõ
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;     // v ‚ğ–K–âÏ‚İ‚É‚·‚é.

    // v ‚©‚ç‚¢‚¯‚éŠe’¸“_ next_v ‚É‚Â‚¢‚Ä
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v ‚ª’TõÏ‚İ‚È‚ç’Tõ‚µ‚È‚¢.
        dfs(G, next_v);
    }
}

int main()
{
    // ’¸“_”‚Æ•Ó”
    int n, m;
    cin >> n >> m;

    // ƒOƒ‰ƒt“ü—Íóæ (‚±‚±‚Å‚Í—LŒüƒOƒ‰ƒt‚ğ‘z’è)
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // ’Tõ
    seen.assign(n, false);
    for (int v = 0; v < n; ++i) {
        if (seen[v]) continue;
        dfs(G, v);
    }
}
