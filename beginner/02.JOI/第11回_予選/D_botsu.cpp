#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int mod = 10000;
typedef vector<vector<int> > vec2d;

vec2d dp0, dp1, dp2; // dp[i][j]：i日目、j日連続 (0 ~ 2)  

void calc1(vec2d &dp0, vec2d &dp1, vec2d &dp2, int i) {
    for (int j = 0; j < 3; ++j) {
        dp0[i+1][j] += (dp1[i][j] + dp2[i][j]);
        dp0[i+1][j] %= mod;
    }
}

void calc2(vec2d &dp0, vec2d &dp1, vec2d &dp2, int i, int j) {
    dp0[i+1][j+1] += dp0[i][j];
    dp1[i+1][j+1] += dp1[i][j];
    dp2[i+1][j+1] += dp2[i][j];

    dp0[i+1][j+1] %= mod;
    dp1[i+1][j+1] %= mod;
    dp2[i+1][j+1] %= mod;
}

void init(int n, int m, vec2d &dp) {
    dp.assign(n+1, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = 0;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        b--;
        mp[a] = b;
    }

    init(n, 3, dp0);
    init(n, 3, dp1);
    init(n, 3, dp2);
    
    dp0[1][1] = 1;
    dp1[1][1] = 1;
    dp2[1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (mp[i]) {
                if (mp[i] == 0) {
                    calc1(dp0, dp1, dp2, i);
                    if (j < 2) dp0[i+1][j+1] += dp0[i][j];
                    for (int k = 0; k < 3; ++k) {
                        dp1[i][k%3] = 0;
                        dp2[i][k%3] = 0;
                    }
                    dp0[i+1][j+1] %= mod;
                } else if (mp[i] == 1) {
                    calc1(dp1, dp2, dp0, i);
                    if (j < 2) dp1[i+1][j+1] += dp1[i][j];
                    for (int k = 0; k < 3; ++k) {
                        dp0[i][k%3] = 0;
                        dp2[i][k%3] = 0;
                    }
                    dp1[i+1][j+1] %= mod;
                } else {
                    calc1(dp2, dp0, dp1, i);
                    if (j < 2) dp2[i+1][j+1] += dp2[i][j];
                    for (int k = 0; k < 3; ++k) {
                        dp0[i][k%3] = 0;
                        dp1[i][k%3] = 0;
                    }
                    dp2[i+1][j+1] %= mod;
                }
            } else {
                calc1(dp0, dp1, dp2, i);
                calc1(dp1, dp2, dp0, i);
                calc1(dp2, dp0, dp1, i);
                if (j < 2) calc2(dp0, dp1, dp2, i, j);
            }
            
            cout << "dp0[i][j] = " << dp0[i][j] << endl;
        }
    }

    long long ans = 0;

    for (int i = 0; i < 3; ++i) {
        ans += dp0[n][i] + dp1[n][i] + dp2[n][i];
        ans %= mod;
    }

    cout << ans << endl;
}
