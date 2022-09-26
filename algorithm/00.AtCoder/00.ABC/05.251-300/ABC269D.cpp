#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, 0, 1};

bool field[2020][2020];
int offset = 1000;

bool seen[2020][2020];

void dfs(int vx, int vy) {
    seen[vx][vy] = true;

    for (int i = 0; i < 6; ++i) {
        int nx = vx + dx[i];
        int ny = vy + dy[i];

        if (nx < 0 || nx > 2000 || ny < 0 || ny > 2000 || field[nx][ny] == false) continue;
        if (seen[nx][ny] == true) continue;

        seen[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> pa;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        field[x+offset][y+offset] = true;

        pa.push_back(make_pair(x+offset, y+offset));
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int xx = pa[i].first;
        int yy = pa[i].second;

        if (seen[xx][yy] == true) continue;
        dfs(xx, yy);

        ans++;        
    }

    cout << ans << endl;
    return 0;
}
