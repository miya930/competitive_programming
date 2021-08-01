#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w, h;

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

vector<vector<int> > field;
vector<vector<bool> > used;

void dfs(int sx, int sy) {
    used[sx][sy] = true;

    for (int i = 0; i < 8; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || field[nx][ny]==0) continue;
        if (used[nx][ny]==true) continue;
        dfs(nx, ny);
    }
}

int main()
{
    while(cin >> w >> h) {
        if (w==0 && h==0) break;

        used.assign(h, vector<bool>(w, false));
        field.assign(h, vector<int>(w));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> field[i][j];
            }
        }

        int ans = 0;
        for (int i = 0 ; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (used[i][j]==true || field[i][j]==0) continue;
                dfs(i, j);
                ans++;
            }
        }
        cout << ans << endl;
    }
} 
