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
    int n;
    cin >> n;
    int cnt = 1;
    
    int dir = 0;
    int curx = 0, cury = 0;
    vector<vector<string>> ans(n+1, vector<string>(n+1, "0"));
    ans[n/2][n/2] = "T";
    while(1) {
        ans[curx][cury] = to_string(cnt);
        cnt++;
        if (cnt >= n*n) break;
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        if ((dir == 0 && (ny >= n || ans[nx][ny] != "0"))) {
            dir++;
            nx = curx + dx[dir];
            ny = cury + dy[dir];
        }
        if ((dir == 1 && (nx >= n || ans[nx][ny] != "0"))) {
            dir++;
            nx = curx + dx[dir];
            ny = cury + dy[dir];
        }
        if ((dir == 2 && (ny < 0 || ans[nx][ny] != "0"))) {
            dir++;
            nx = curx + dx[dir];
            ny = cury + dy[dir];
        }
        if ((dir == 3 && (nx < 0 || ans[nx][ny] != "0"))) {
            dir++;
            dir %= 4;
            nx = curx + dx[dir];
            ny = cury + dy[dir];
        }
        curx = nx;
        cury = ny;

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
