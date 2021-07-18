#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];

    // aÅF0, bÅF1, cÅF2
    vector<vector<int> > dp(n+1, vector<int>(3, 0));
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;

    for (int i = 1; i <= n; ++i) {
        chmax(dp[i][0], dp[i - 1][1] + b[i - 1]);
        chmax(dp[i][0], dp[i - 1][2] + c[i - 1]);
        chmax(dp[i][1], dp[i - 1][0] + a[i - 1]);
        chmax(dp[i][1], dp[i - 1][2] + c[i - 1]);
        chmax(dp[i][2], dp[i - 1][0] + a[i - 1]);
        chmax(dp[i][2], dp[i - 1][1] + b[i - 1]);
    }
    cout << max({ dp[n][0], dp[n][1] , dp[n][2]}) << endl;
    return 0;
}
