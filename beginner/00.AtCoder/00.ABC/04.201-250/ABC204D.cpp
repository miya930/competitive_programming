#include <iostream>
#include <vector>
using namespace std;
const int MA = 100010;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += t[i];

    vector<vector<int> > dp(n+1, vector<int>(MA, 0));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < MA; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j >= t[i]) dp[i+1][j] |= dp[i][j-t[i]];
        }
    }

    int ans = MA;
    int mid = (sum+1)/2;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < MA-mid; ++j) {
            if (dp[i][mid+j]) ans = min(ans, mid+j);
        }
    }
    cout << ans << endl;
}
