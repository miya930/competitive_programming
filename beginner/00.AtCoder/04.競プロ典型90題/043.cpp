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
