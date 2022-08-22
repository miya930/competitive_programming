#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> G(h);
    for (int i = 0 ; i < h; ++i) cin >> G[i];

    bool cycle = false;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    int cx = 0, cy = 0;
    while(1) {
        if (seen[cx][cy] == true) {
            cycle = true;
            break;
        }

        seen[cx][cy] = true;

        int nx = cx, ny = cy;
        if (G[cx][cy] == 'U') {
            nx--;
        } else if (G[cx][cy] == 'D') {
            nx++;
        } else if (G[cx][cy] == 'L') {
            ny--;
        } else if (G[cx][cy] == 'R') {
            ny++;
        }
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) break;

        cx = nx;
        cy = ny;
    }

    if (cycle == true) cout << -1 << endl;
    else cout << cx+1 << " " << cy+1 << endl;

    return 0;
}
