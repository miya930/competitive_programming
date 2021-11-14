#include <iostream>
#include <vector>
using namespace std;
int n, p;

int main()
{
    cin >> n >> p;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<long long> > dp(n+1, vector<long long>(5100, 0)); 
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 5000; ++j) {
            dp[i+1][j+a[i]] += dp[i][j];
            dp[i+1][j] += dp[i][j];
        }
    }

    long long ans = 0;
    for (int j = 0; j <= 5000; ++j) {
        if (j%2 == p) ans += dp[n][j];
    }
    cout << ans << endl;
    return 0;
}   
