#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000009;

int main(void)
{
    int n, A;
    cin >> n >> A;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int> > dp(n, vector<int>(A+1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) cin >> dp[0][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= A; j++) {
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if (j-a[i]>=) (dp[j+1][i] += dp[i][j-a[i]]) %= MOD;
        }
    }
    
    cout << dp[n][A] << endl;
}
