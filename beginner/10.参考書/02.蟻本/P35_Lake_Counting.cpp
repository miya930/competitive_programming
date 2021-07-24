#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int field[110][110];

bool dfs(int sx, int sy) {
    field[sx][sy] = '.';

    for (int i = 0; i < 8; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];

        if (0 <= nx || nx < n || ny >= 0 || ny < m || field[nx][ny] == 'W') dfs(nx, ny);
    }
    return 0;
}

void solve()
{
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'W') {
                dfs(i, j);
                res++;
            }
        }
    }
}
