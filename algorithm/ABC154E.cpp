#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[110][110];

int main()
{
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();
    for (int i = 1; i <= n+1; ++i) {
        for (int j = 0; j <= n+1; ++j) {
            dp[i+1][j] += dp[i][j];
            for (int l = 0; l <= 9; ++l) {
                
            }

        }
            
    }

    return 0;
}
