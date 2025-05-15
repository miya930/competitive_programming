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

struct Edge {
    int to;
    int x;
    int y;
    Edge(int to, int x, int y): to(to), x(x), y(y) {};
};

using Graph = vector<vector<Edge>>;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    rep(i, 0, m) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--; b--;
        G[a].push_back(Edge(b, x, y));
        G[b].push_back(Edge(a, -x, -y));
    }

    vector<pair<ll,ll>> ans(n, make_pair(-infl, -infl));
    ans[0].first = 0;
    ans[0].second = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {

            if (ans[nv.to].first != -infl) continue;

            ans[nv.to].first = ans[v].first + nv.x;
            ans[nv.to].second = ans[v].second + nv.y;

            que.push(nv.to);
        }
    }
    rep(i, 0, n) {
        if (ans[i].first == -infl) cout << "undecidable" << endl;
        else cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
