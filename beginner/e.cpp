#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll dp[1010][1<<10][10];

ll ret(int i, int bit, int cnt, string s) {

    int shift = s[i] - 'A';
    if (bit>>shift & 1) dp[i+1][]
}


int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    dp[1][1<<(s[0]-'A')][s[0]-'A'] = 1;

    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < 1<<10; ++bit) {
            int shift = s[i] - 'A';
            if (1>>shift & 1) {
                dp[i+1][]
            }
            for (int j = 0; j <10; ++j) {
                if (bit>>j & ) 
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;

}
