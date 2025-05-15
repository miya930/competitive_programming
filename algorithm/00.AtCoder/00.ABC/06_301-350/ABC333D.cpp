#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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

vector<int> vec;
vector<bool> seen;

void dfs(Graph &G, int v, int &cnt) {
    seen[v] = true;
    cnt++;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;

        dfs(G, nv, cnt);

        if (v == 0) {
            vec.push_back(cnt);
            cnt = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Graph G(n);
    seen.assign(n, false);
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int c = -1;
    dfs(G, 0, c);
    sort(vec.begin(), vec.end());
    int m = vec.size();
    int ans = 0;
    rep(i, 0, m-1) {
        ans += vec[i];
    }
    cout << ans+1 << endl;

    return 0;
}
