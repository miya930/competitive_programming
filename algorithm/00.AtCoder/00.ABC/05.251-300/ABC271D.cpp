#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(110, vector<bool>(11000, false));
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i][j] != true) continue;

            if (j+a[i] <= 10000) dp[i+1][j+a[i]] = true;
            if (j+b[i] <= 10000) dp[i+1][j+b[i]] = true;
        }
    }

    string ans = "";

    if (dp[n][s]) {
        cout << "Yes" << endl;

        int cur = n-1;
        int sum = s;
        while(1) {
            if (cur == -1) break;

            if (sum-a[cur] >= 0 && dp[cur][sum-a[cur]]) {
                ans += 'H';
                sum -= a[cur];
            } else if (sum-b[cur] >= 0 && dp[cur][sum-b[cur]]) {
                ans += 'T';
                sum -= b[cur];
            }

            cur--;
        }

        reverse(ans.begin(), ans.end());

        cout << ans << endl;

    } else {
        cout << "No" << endl;
    }

    return 0;
}
