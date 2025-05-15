#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    int ex = -1, ey = -1;
    queue<pii> que;
    rep(i, 0, h) rep(j, 0, w) {
        if (s[i][j] == 'E') {
            ey = i;
            ex = j;
            que.push(make_pair(ey, ex));
        }
    }
    if (ex == -1) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) cout << s[i][j];
            cout << endl;
        }
        return 0;
    }
    vector<string> t = s;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[ey][ex] = 0;
    while(!que.empty()) {
        int vy = que.front().first;
        int vx = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int ny = vy + dy[i];
            int nx = vx + dx[i];
            if (ny >= h || ny < 0 || nx >= w || nx < 0 || s[ny][nx] == '#' || s[ny][nx] == 'E') continue;
            if (dist[ny][nx] != inf) continue;

            dist[ny][nx] = dist[vy][vx] + 1;
            que.push(make_pair(ny, nx));

            if (nx == vx && ny < vy) {
                t[ny][nx] = 'v';
            } else if (nx == vx && ny > vy) {
                t[ny][nx] = '^';
            } else if (nx < vx && ny == vy) {
                t[ny][nx] = '>';
            } else {
                t[ny][nx] = '<';
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cout << t[i][j];
        cout << endl;
    }

    return 0;
}
