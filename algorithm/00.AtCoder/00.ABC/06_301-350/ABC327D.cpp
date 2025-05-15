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
vector<int> isseen;

void dfs(Graph &G, int v, int c) {
    isseen[v] = c;

    for(auto nv : G[v]) {
        if (isseen[nv] != -1) {
            if (isseen[nv] == isseen[v]) {
                cout << "No" << endl;
                exit(0);
            } else {
                continue;
            }
        }
        dfs(G, nv, 1 - c);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    isseen.assign(n, -1);

    map<pair<int,int> , int> mp;
    vector<int> a(m), b(m);
    rep(i, 0, m) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    rep(i, 0, m) {
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    rep(i, 0, n) {
        if (isseen[i] != -1) continue;
        dfs(G, i, 1);
    }
    cout << "Yes" << endl;
    return 0;
}
