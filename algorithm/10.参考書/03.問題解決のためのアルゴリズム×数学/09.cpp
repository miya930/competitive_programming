#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<bool>> dp(n+1, vector<bool>(s+1, 0));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j+a[i] <= s) dp[i+1][j+a[i]] = dp[i][j] | dp[i+1][j+a[i]];
            dp[i+1][j] = dp[i+1][j] | dp[i][j];
        }
    }    

    if (dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}
