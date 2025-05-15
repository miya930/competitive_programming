#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> s(h, vector<char>(w, 'w'));
    int curx = 0, cury = 0;
    int dir = 0;
    rep(i, 0, n) {
        if (s[curx][cury] == 'w') {
            dir = (dir + 1) % 4;
            s[curx][cury] = 'b';
        } else {
            dir = (dir - 1 + 4) % 4;
            s[curx][cury] = 'w';
        }
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        nx = (nx + h) % h;
        ny = (ny + w) % w;
        curx = nx;
        cury = ny;
    }

    rep(i, 0, h) {
        rep(j ,0 ,w) {
            if (s[i][j] == 'w') cout << '.';
            else cout << '#';
        }
        cout << endl;
    }

    return 0;
}
