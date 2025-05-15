#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };
using Graph = vector<vector<int>>;
vector<bool> first, last;
vector<int> hist;
bool is_cycle = false;

int dfs(Graph &G, int v, int p) {
    first[v] = true;
    hist.push_back(v);

    for (auto nv : G[v]) {
        if (nv == p) continue;
        if (last[nv]) continue;

        if (first[nv] && !last[nv]) {
            hist.push_back(nv);
            is_cycle = true;
            return nv;
        }
        int pos = dfs(G, nv, v);
        if (pos != -1) return pos;
    }
    last[v] = true;
    hist.pop_back();
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    first.assign(n, false);
    last.assign(n, false);
    int pos =dfs(G, 0, -1);
    
    vector<int> cycle;
    int cnt = 0;
    while(!hist.empty()) {
        int v = hist.back();
        if (v == pos) cnt++;
        if (cnt >= 2) break;
        cycle.push_back(v);
        hist.pop_back();
    }
    int cycle_size = cycle.size();

    if (is_cycle && cycle_size == n && m == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
