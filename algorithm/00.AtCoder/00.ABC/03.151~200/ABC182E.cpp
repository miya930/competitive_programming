#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool block[1510][1510];

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
        block[c[i]][d[i]] = true;
    }
    
    for (int pos = 0; pos < n; ++pos) {
        int vx = a[pos];
        int vy = b[pos];
        
        if (seen[vx][vy]) continue;

        seen[vx][vy] = true;
        ans++;
        for (int i = vx+1; i < h; ++i) {
            if (block[i][vy]) break;
            if (seen[i][vy] == false) ans++;
            seen[i][vy] = true;
        }
        for (int i = vx-1; i >= 0; --i) {
            if (block[i][vy]) break;
            if (seen[i][vy] == false) ans++;
            seen[i][vy] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        seen[a[i]][b[i]] = false;
    }

    for (int pos = 0; pos < n; ++pos) {
        int vx = a[pos];
        int vy = b[pos];
        
        if (seen[vx][vy]) continue;
        ans++;
        seen[vx][vy] = true;
        for (int i = vy+1; i < w; ++i) {
            if (block[vx][i]) break;
            if (seen[vx][i] == false) ans++;
            seen[vx][i] = true;
        }
        for (int i = vy-1; i >= 0; --i) {
            if (block[vx][i]) break;
            if (seen[vx][i] == false) ans++;
            seen[vx][i] = true;
        }
    }

    cout << ans-n << endl;
    return 0;
}
