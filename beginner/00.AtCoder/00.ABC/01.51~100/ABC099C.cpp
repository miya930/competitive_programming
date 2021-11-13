#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    for (int i = 6; i > 0; --i) {
        int j = 9;
        int cnt = i;
        int temp = 1;
        while (cnt > 0) {
            temp *= j;
            cnt--;
        }
        if (temp != 1) vec.push_back(temp);
    }
    for (int i = 7; i > 0; --i) {
        int j = 6;
        int cnt = i;
        int temp = 1;
        while (cnt > 0) {
            temp *= j;
            cnt--;
        }
        if (temp != 1) vec.push_back(temp);
    }
    vec.push_back(1);

    vector<vector<int> > dp(200, vector<int>(100100, inf));
    dp[0][0] = 0;

    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j <= 100000; ++j) {
            for (int k = 0; k < vec.size(); ++k) {
                if (dp[i][j] < inf) {
                    if (j+vec[k] <= 100000) {
                        chmin(dp[i+1][min(j+vec[k], 100010)], dp[i][j]+1);
                    }
                    chmin(dp[i+1][j], dp[i][j]);
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < 50; ++i) {
        if (dp[i][n] < inf) ans = min(ans, dp[i][n]);
    }

    cout << ans << endl;

    return 0;
}
