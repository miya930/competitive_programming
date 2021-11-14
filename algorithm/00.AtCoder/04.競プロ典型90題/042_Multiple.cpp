/**
 * 
 * ã£ÉvÉçìTå^90ñ‚
 * 042 - Multiple of 9 (Åö4)
 * link : https://atcoder.jp/contests/typical90/tasks/typical90_ap
 * 
 */

#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int k;
    cin >> k;

    if (k % 9 == 0) {
        vector<int> dp(k+1);
        dp[0] = 1;
        for (int i = 1; i < k+1; ++i) {
            for (int j = i-1; j >= i - 9 && j >= 0; --j) {
                dp[i] += dp[j];
                if (dp[i] >= MOD) dp[i] %= MOD;
            }
        }
        cout << dp[k] << endl;
    } else {
        cout << 0 << endl;
    }

}
