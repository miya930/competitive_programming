#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n; ++i) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n+1, vector<bool>(x+100, 0));
    dp[0][0] = true;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x+1; ++j) {
            if (j+a[i] <= x) dp[i+1][j+a[i]] = dp[i+1][j+a[i]] | dp[i][j];
            if (j+b[i] <= x) dp[i+1][j+b[i]] = dp[i+1][j+b[i]] | dp[i][j];
        }
    }

    if (dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
