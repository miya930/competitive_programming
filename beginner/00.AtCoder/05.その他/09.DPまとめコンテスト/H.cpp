#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const long long mod = 1000000007;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; ++i) cin >> s[i];

    vector<vector<long long> > dp(H+1, vector<long long>(W+1, 0));
    dp[0][0] = 1;

    for (long long y = 0; y < H; ++y) {
        for (long long x = 0; x < W; ++x) {
            if(y + 1 < H && s[y+1][x] != '#') {
                dp[y+1][x] += dp[y][x];
                dp[y+1][x] = dp[y+1][x] % mod;
            } 
            if(x + 1 < W && s[y][x+1] != '#') {
                dp[y][x+1] += dp[y][x];
                dp[y][x+1] = dp[y][x+1] % mod;
            }
        }
    }
    cout << dp[H-1][W-1] << endl;
}
