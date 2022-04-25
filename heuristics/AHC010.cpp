#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int row = 30;
const int col = 30;
vector<string> t(row);
string ans = "";

/* input / output */
void input(void) {
    for (int i  = 0 ; i < row; ++i) cin >> t[i];
}
void output(void) {
    cout << ans << endl;
}

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int to[][4] = {
    {1, 0, -1, -1},
    {3, -1, -1, 0},
    {-1, -1, 3, 2},
    {-1, 2, 1, -1},
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {2, -1, 0, -1},
    {-1, 3, -1, 1}
};
int rotate[] = {1, 2, 3, 0, 5, 4, 7, 6};

int check(int sx, int sy) {
    int res = 0;
    int x = sx, y = sy;
    int d;
    for (int i = 0; i < 4; ++i) {
        if (to[t[sx][sy] - '0'][i] != -1) {
            d = i;
            break;
        }
    }
    int sd = d;

    cout << sx << " " << sy << " " << to[t[sx][sy] - '0'][0] << endl;

    while(1) {
        int d2 = to[t[x][y]][d];
        if (d2 == -1) return 0;
        x += dx[d2];
        y += dy[d2];
        if (x < 0 || x >= 30 || y < 0 || y >= 30) return 0;
    
        d = (d2 + 2) % 4;
        res++;
        if (x == sx && y == sy && d == sd) return res;
    }
}

int main()
{
    input();
    
    cout << check(7, 5) << endl;

    output();

    return 0;
}
