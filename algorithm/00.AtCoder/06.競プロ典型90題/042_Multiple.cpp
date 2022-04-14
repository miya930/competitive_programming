/**
 * 
 * ���v���T�^90��
 * 042 - Multiple of 9 (��4)
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

/* 2022.4.10 復習 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int n = 100100;
vector<int> dp(n+1);

int main()
{
    int k;
    cin >> k;
    
    for (int i = 1; i < 10; ++i) dp[i] = 1;

    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < 10; j++) {
            if (i+j <= k) dp[i+j] += dp[i];
            dp[i+j] %= mod;
        }
    }

    if (k%9 == 0) cout << dp[k] << endl;
    else cout << 0 << endl;
    return 0;
}
