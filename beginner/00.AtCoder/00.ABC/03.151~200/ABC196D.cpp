#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool used[20][20];
int H, W;

int dfs(int x, int y, int a) {
    if (H == y) return a == 0;
    if (W == x) return dfs(0, y + 1, a);
    if (used[y][x]) return dfs(x + 1, y, a);

    int res = 0;

    // c’u‚«
    if (y+1 < H && !used[y+1][x] && 0 < a) {
        used[y][x] = used[y+1][x] = true;
        res += dfs(x+1, y, a-1);
        used[y][x] = used[y+1][x] = false;
    }

    // ‰¡’u‚«
    if (x+1 < W && !used[y][x+1] && 0 < a) {
        used[y][x] = used[y][x+1] = true;
        res += dfs(x+1, y, a-1);
        used[y][x] = used[y][x+1] = false;
    }

    // ‰½‚à’u‚©‚È‚¢
    res += dfs(x+1, y, a);

    return res;
}

int main()
{
    int a, b;
    cin >> H >> W >> a >> b;
    cout << dfs(0, 0, a) << endl;

}