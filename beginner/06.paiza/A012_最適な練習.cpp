#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int inf = 1001001001;

int dp[15][40][40][40][40];

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > t(n, vector<int>(4)), a(m, vector<int>(4));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> t[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int t1 = 0; t1 <= 30; t1++) {
            for (int t2 = 0; t2 <= 30; t2++) {
                for (int t3 = 0; t3 <= 30; t3++) {
                    for (int t4 = 0; t4 <= 30; t4++) {
                        dp[i][t1][t2][t3][t4] = inf;
                    }
                }
            }
        }
    }

    dp[0][0][0][0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int t1 = 0; t1 <= 30; t1++) {
            for (int t2 = 0; t2 <= 30; t2++) {
                for (int t3 = 0; t3 <= 30; t3++) {
                    for (int t4 = 0; t4 <= 30; t4++) {
                        if (dp[i][t1][t2][t3][t4] < inf) {
                            chmin(dp[i+1][min(t1+t[i][0], 30)][min(t2+t[i][1], 30)][min(t3+t[i][2], 30)][min(t4+t[i][3], 30)],dp[i][t1][t2][t3][t4]+1);
                            chmin(dp[i][min(t1+t[i][0], 30)][min(t2+t[i][1], 30)][min(t3+t[i][2], 30)][min(t4+t[i][3], 30)],dp[i][t1][t2][t3][t4]+1);
                            chmin(dp[i+1][t1][t2][t3][t4], dp[i][t1][t2][t3][t4]);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int ans = inf;
        for (int j = 0; j <= n; ++j) {
            for (int t1 = a[i][0]; t1 <= 30; ++t1) {
                for (int t2 = a[i][1]; t2 <= 30; ++t2) {
                    for (int t3 = a[i][2]; t3 <= 30; ++t3) {
                        for (int t4 = a[i][3]; t4 <= 30; ++t4) {
                            ans = min(ans, dp[j][t1][t2][t3][t4]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }    

    return 0;
}
