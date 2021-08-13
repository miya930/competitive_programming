#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<ll> > dp(n+10, vector<ll>(30, 0));
    dp[1][a[0]] = 1;

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j <= 20; j++) {
            if (j+a[i] <= 20) dp[i+1][j+a[i]] += dp[i][j];
            if (j-a[i] >= 0) dp[i+1][j-a[i]] += dp[i][j];
        }
    }

    cout << dp[n-1][a[n-1]] << endl;
}
