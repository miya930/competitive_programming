#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool dp[110][100010];

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= s; ++j) {
            if (j+a[i] <= s) dp[i+1][j+a[i]] |= dp[i][j];
            if (j+b[i] <= s) dp[i+1][j+b[i]] |= dp[i][j];
        }
    }

    string ans = "";
    if (dp[n][s]) {
        while(n > 0) {
            if (s-a[n-1]>=0 && dp[n-1][s-a[n-1]]) {
                s -= a[n-1];
                ans = ans + "A";
            } else {
                if (s-b[n-1] < 0) continue;
                s -= b[n-1];
                ans = ans + "B";
            }
            n--;
        }
    } else {
        cout << "Impossible" << endl;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;

}
