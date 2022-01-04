#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

void chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> dp(n+1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (i+1 < n) chmin(dp[i+1], dp[i]+abs(h[i+1]-h[i]));
        if (i+2 < n) chmin(dp[i+2], dp[i]+abs(h[i+2]-h[i]));
    }

    cout << dp[n-1] << endl;
    return 0;
}
