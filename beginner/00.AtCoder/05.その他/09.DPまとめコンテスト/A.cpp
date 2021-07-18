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
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        chmin(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        if (i > 1) chmin(dp[i], dp[i-2]+abs(h[i]-h[i-2])); 
    }
    cout << dp[n-1] << endl;
}
