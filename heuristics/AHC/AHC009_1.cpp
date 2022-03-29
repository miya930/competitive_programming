/* 自明解 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ver = 20;
const int hor = 19;
const int ma  = 200;
int sx, sy, tx, ty, p;
vector<string> h(ver), v(ver);
string ans = "";

void input(void) {
    cin >> sx >> sy >> tx >> ty >> p;
    for (int i = 0; i < ver; ++i) cin >> h[i];
    for (int i = 0; i < ver; ++i) cin >> v[i];
    return;
}

int diffx, diffy;
char dirx, diry;

int main()
{
    input();

    diffx = tx - sx; diffy = ty - sy;

    if (diffx >= 0) dirx = 'D';
    else dirx = 'U';
    if (diffy >= 0) diry = 'L';
    else diry = 'R';

    for (int i = 0; i < ma; ++i) {
        if (i%2 == 0) ans += dirx;
        else ans += diry;
    }

    cout << ans << endl;
    return 0;
}
