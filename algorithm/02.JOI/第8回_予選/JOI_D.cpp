#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int m, n, ans;
vector<vector<int> > field(100, vector<int>(100));

vector<vector<int> > dp;

void dfs(int sx, int sy, int cnt) {
    field[sx][sy] = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = sx + dx[i], ny = sy + dy[i];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || field[nx][ny]==0) continue;

        dfs(nx, ny, cnt+1);
    }

    if (ans < cnt) ans = cnt;
    field[sx][sy] = 1;
    
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> field[i][j];
        }
    }

    ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j]==0) continue;
            dfs(i, j, 1);
        }
    }

    cout << ans << endl;
}
