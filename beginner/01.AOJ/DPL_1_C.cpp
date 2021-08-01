#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];

    vector<vector<int> > dp(n+1, vector<int>(W+1, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            chmax(dp[i+1][j], dp[i][j]);
            if(j >= w[i]) {
                chmax(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
            }
        }
    }

    cout << dp[n][W] << endl;
}
