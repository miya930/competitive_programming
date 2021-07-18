#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i+j > n-1) continue;
            chmin(dp[i+j], dp[i]+abs(h[i+j]-h[i]));
        }
    }
    cout << dp[n-1] << endl;
}
