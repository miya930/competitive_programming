#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n, C;
    cin >> n >> C;

    vector<vector<int>> d(C, vector<int>(C)), c(n, vector<int>(n));
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) cin >> d[i][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector<vector<int>> ch(3, vector<int>(40, 0));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            for (int k = 0; k < C; ++k) {
                int t = (x+y)%3;
                int color = c[x][y];
                int p = d[color][k];
                ch[t][k] += p;  // (x+y)%3 == t のマスすべてをkに変えるのに必要なポイント
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                if (i == j || j == k || k == i) continue;
                int tmp = ch[0][i] + ch[1][j] + ch[2][k];
                ans = min(ans, tmp);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
