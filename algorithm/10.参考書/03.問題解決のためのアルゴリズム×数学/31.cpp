#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> void chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));

    for (int i = 0; i < n; ++i) {
        chmax(dp[i+1][1], dp[i][0]+a[i]);
        chmax(dp[i+1][0], dp[i][1]);
        chmax(dp[i+1][0], dp[i][0]);
    }

    cout << max(dp[n][1], dp[n][0]) << endl;
    return 0;
}
