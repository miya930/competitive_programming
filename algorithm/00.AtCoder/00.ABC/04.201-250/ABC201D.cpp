#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int h, w;
vector<string> a;
vector<vector<bool>> vis(2020, vector<bool>(2020));
vector<vector<int>> memo(2020, vector<int>(2020));

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int dp(int x, int y) {
    if (vis[x][y]) return memo[x][y];
    vis[x][y] = true;

    int turn = (x+y)%2;

    if (x == h-1 && y == w-1) return memo[x][y] = 0;

    if (turn == 0) {
        memo[x][y] = -inf;
        if (x < h-1) chmax(memo[x][y], dp(x+1, y) + (a[x+1][y] == '+' ? 1 : -1));
        if (y < w-1) chmax(memo[x][y], dp(x, y+1) + (a[x][y+1] == '+' ? 1 : -1));
        return memo[x][y];
    } else {
        memo[x][y] = inf;
        if (x < h-1) chmin(memo[x][y], dp(x+1, y) - (a[x+1][y] == '+' ? 1 : -1));
        if (y < w-1) chmin(memo[x][y], dp(x, y+1) - (a[x][y+1] == '+' ? 1 : -1));
        return memo[x][y];
    }
    
}

int main()
{
    cin >> h >> w;
    a.resize(h);
    for (int i = 0; i < h; ++i) cin >> a[i];

    int opt = dp(0, 0);
    
    if (0 < opt) cout << "Takahashi" << endl;
    else if (opt == 0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
 