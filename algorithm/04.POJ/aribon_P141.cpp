#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int dx[] = {-1, 0, 0, 1, 0};
int dy[] = {0, -1, 0, 0, 1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
        }
    }

    vector<vector<int>> ans(m, vector<int>(n));
    int mi = inf;

    for (int bit = 0; bit < (1<<n); bit++) {
        vector<vector<int>> tmp(m, vector<int>(n, 0)), fieldtmp = field;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((bit>>i)&1) {
                tmp[0][i] = 1;
                cnt++;
                for (int d = 0; d < 5; d++) {
                    int nx = 0 + dx[d];
                    int ny = i + dy[d];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                    fieldtmp[nx][ny] = 1 - fieldtmp[nx][ny];
                } 
            }
        }
        
        for (int i = 1; i < m-1; i++) {
            for (int j = 0; j < n; j++) {
                int t = fieldtmp[i-1][j];
                if (t%2 == 0) continue;
                else {
                    tmp[i][j] = 1;
                    cnt++;
                    for (int d = 0; d < 5; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                        fieldtmp[nx][ny] = 1 - fieldtmp[nx][ny];
                    }
                }
            }
        }

        bool isok = true;
        for (int i = 0; i < n; i++) {
            if (fieldtmp[n-1][i] == 1) isok = false;
        }

        if (isok) {
            if (cnt < mi) {
                mi = cnt;
                ans = tmp;
            }
        }

    }

    if (mi == inf) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
