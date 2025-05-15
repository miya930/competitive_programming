#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

struct UnionFind {
    vector<int> par, siz;

    void init(int n) {
        par.assign(n, -1);
        siz.assign(n, 1);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        if (siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }

};

UnionFind uf;


int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    uf.init(h*w);
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] != '#') continue;
            int idx = w * i + j;
            rep(k, 0, 8) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '.') continue;
                int nidx = w * nx + ny;
                uf.unite(idx, nidx);
            }
        }
    }
/*    queue<int> que;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    rep(i, 0, h) rep(j, 0, w) {
        if (seen[i][j]) continue;
        if (s[i][j] == '.') continue;
        queue<pair<int,int>> que;
        que.push(make_pair(i, j));
        while(!que.empty()) {
            int vx = que.front().first;
            int vy = que.frotn().second;
            que.pop();

            rep(k, 0, 8) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (seen[nx][ny]) continue;
                int nidx = w * nx + ny;
                uf.unite(idx, nidx);
            }
        }
    }*/

    map<int,int> mp;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] == '.') continue;
            int idx = w * i + j;
            int roo = uf.root(idx);
            if (mp.count(roo) == 0) {
                mp[roo]++;
            }
        }
    }
    cout << (int)mp.size() << endl;

    return 0;
}
