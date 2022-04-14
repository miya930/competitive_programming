#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
const int inf = 1000000007;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct state {
    int x, y, dir;
};

int dist[1009][1009][4];

int main()
{
    int H, W;
    cin >> H >> W;

    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    --sx, --sy, --gx, --gy;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            dist[i][j][0] = inf;
            dist[i][j][1] = inf;
            dist[i][j][2] = inf;
            dist[i][j][3] = inf;
        }
    }

    vector<string> s(H);
    for (int i = 0; i < H; ++i) cin >> s[i];

    deque<state> deq;
    for (int i = 0; i < 4; ++i) {
        dist[sx][sy][i] = 0;
        deq.push_back({ sx, sy, i });
    }

    while (!deq.empty()) {
        state u = deq.front(); deq.pop_front();
        for (int i = 0; i < 4; ++i) {
            int tx = u.x + dx[i], ty = u.y + dy[i], cost = dist[u.x][u.y][u.dir] + (u.dir != i ? 1 : 0);
            if (0 <= tx && tx < H && 0 <= ty && ty < W && s[tx][ty] == '.' && dist[tx][ty][i] > cost) {
                dist[tx][ty][i] = cost;
                if (u.dir != i) deq.push_back({ tx, ty, i });
                else deq.push_front({ tx, ty, i });
            }
        }
    }
    int answer = inf;
    for (int i = 0; i < 4; ++i) {
        answer = min(answer, dist[gx][gy][i]);
    }
    cout << answer << endl;
    return 0;



}


/* 2022.4.10復習 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ppi = pair<pair<int,int>,int>;
const int inf = 1001001001;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int h, w;

int cnt[1010][1010][4];
bool seen[1010][1010][4];
deque<ppi> dq;
vector<string> s;

void bfs(int x, int y) {

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#') continue;
        dq.push_back({{nx, ny}, i});
        cnt[nx][ny][i] = 0;
    }

    while(!dq.empty()) {
        int vx = dq.front().first.first;
        int vy = dq.front().first.second;
        int dir = dq.front().second;
        dq.pop_front();

        if (seen[vx][vy][dir]) continue;
        seen[vx][vy][dir] = true;
        
        for (int i = 0; i < 4; ++i) {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#') continue;

            int p = cnt[vx][vy][dir];
            if (dir != i) p++;

                cnt[nx][ny][i] = p;
                if (dir == i) dq.push_front({{nx,ny}, i});
                else dq.push_back({{nx,ny}, i});
            }
        }
    }
}

int main()
{
    int rs, rt, cs, ct;
    cin >> h >> w >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;

    s.resize(h);
    for (int i = 0; i < h; ++i) cin >> s[i];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int l = 0; l < 4; ++l) {
                cnt[i][j][l] = inf;
            }
        }
    }

    bfs(rs, cs);

    int ans = inf;
    for (int i = 0; i < 4; ++i) ans = min(ans, cnt[rt][ct][i]);

    cout << ans << endl;
    return 0;
}
