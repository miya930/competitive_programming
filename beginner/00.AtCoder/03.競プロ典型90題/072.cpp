#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int H, W, ans = -1;
vector<string> s;
vector<vector<int> > used;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

void dfs(int sx, int sy, int px, int py, int cnt) {
    if (sx == px && sy == py && used[px][py] != -1) {    // sx, sy：ゴール地点
        chmax(ans, cnt);
        return;
    }
    used[px][py] = cnt + 1;

    for (int i = 0; i < 4; ++i) {
        int nx = px + dx[i], ny = py + dy[i];
        if (nx < 0 || nx >= H || ny < 0 || ny >= W || s[nx][ny]=='#') continue;
        if (((sx != nx) || (sy != ny)) && used[nx][ny] != -1) continue;             // (sx == nx) && (sy == ny) の否定を取っている (ドモルガン)
        dfs(sx, sy, nx, ny, used[px][py]); 
    }
    used[px][py] = -1;
}


int main()
{
    cin >> H >> W;
    s.resize(H);
    for (int i = 0; i < H; ++i) cin >> s[i];
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            used.assign(H, vector<int>(W, -1));
            dfs(i, j, i, j, 0);
        }
    }

    if (ans <= 2) cout << -1 << endl;
    else cout << ans << endl;
}
