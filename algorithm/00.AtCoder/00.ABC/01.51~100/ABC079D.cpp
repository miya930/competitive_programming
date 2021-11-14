#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const long long INF = 1LL << 60;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<long long> > dp(10, vector<long long>(10, INF));
    vector<vector<long long> > a(h, vector<long long>(w));
    map<int, long long> mp;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            long long c;
            cin >> c;
            dp[i][j] = c;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int b; cin >> b;
            a[i][j] = b;
            if (b != -1 && b != 1) mp[b]++;
        }
    }

    for (int v = 0; v < 10; ++v) dp[v][v] = 0;

    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    long long ans = 0;
    for (auto v : mp) {
        ans += dp[v.first][1]*v.second;
    }

    cout << ans << endl;
}
