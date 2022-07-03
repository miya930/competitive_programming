#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    int h,w,r,c;
    cin >> h >> w >> r >> c;
    
    int ans = 0;
    for (int i = 0; i < 4; ++i ) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;

        ans++;
    }

    cout << ans << endl;
    return 0;
}
