/***
 * 参考HP
 * https://betrue12.hateblo.jp/entry/2020/03/29/232441
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 10000;
using ll = long long;

int dp[110][3][3];   

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> f(n, -1);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        f[a] = b;
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int a = 0; a < 3; ++a) {
            for (int b = 0; b < 3; ++b) {
                
                vector<int> cs = {0, 1, 2};
                if (f[i]>=0) cs = {f[i]};

                for (int c : cs) {
                    if (i >= 2 && a == b && b == c) continue;
                    dp[i+1][b][c] += dp[i][a][b];
                    dp[i+1][b][c] %= mod;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    
    cout << ans << endl;
    return 0;

}
