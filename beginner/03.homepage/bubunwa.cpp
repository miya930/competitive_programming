#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, A;
    cin >> n >> A;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int> > dp(n+1, vector<int>(A, false));

    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= A; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j-a[i]>=0) dp[i+1][j] |= dp[i][j-a[i]];
        }
    }

    cout << dp[n][A] << endl;
}
