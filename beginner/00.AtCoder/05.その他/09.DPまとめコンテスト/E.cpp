#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
}

int main()
{
    long long n, W;
    cin >> n >> W;

    vector<long long> w(n), v(n);
    vector<vector<long long> > dp(n+1, vector<long long>(200100, INF));
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
    dp[0][0] = 0;

    long long ans = 0;
    for (long long i = 0 ; i < n; ++i) {
        for (long long j = 0; j < 100100; ++j) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][j+v[i]], dp[i][j]+w[i]);
        }
    }

    for (long long i = 0; i < 100100; ++i) {
        if (dp[n][i] <= W) chmax(ans, i); 
    }
    cout << ans << endl;
}
