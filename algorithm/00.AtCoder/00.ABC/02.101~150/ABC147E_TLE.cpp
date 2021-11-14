#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
const int INF = 1000000007;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int field[100][100][2];
int ans = INF;
int h, w;

void dfs(int sx, int sy, int sum) {
    if (sx == h-1 && sy == w-1) {
        ans = min(ans, abs(sum));
    }

    for (int i = 0; i < 2; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

        for (int j = 0; j < 2; ++j) {
            dfs(nx, ny, sum+field[nx][ny][j]);
        }
    }
}

int main()
{
    cin >> h >> w;
    vector<vector<int> > a(h, vector<int>(w)), b(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0;j < w; ++j) {
            field[i][j][0] = a[i][j] - b[i][j];
            field[i][j][1] = b[i][j] - a[i][j];
        }
    }

    dfs(0, 0, a[0][0]-b[0][0]);
    dfs(0, 0, b[0][0]-a[0][0]);

    cout << ans << endl;

}
