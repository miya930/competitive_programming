#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const long long MOD = 1000000007;
typedef long long ll;
vector<vector<ll> > dp(100300, vector<ll>(2, 0)); // +F0, -F1

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp[1][0] = a[0];

    ll fibo_1 = 1, fibo_2 = 1;
    for (int i = 1; i < n; ++i) {
        dp[i + 1][0] = ((dp[i][0] + dp[i][1]) + (fibo_1 * a[i]))%MOD;
        dp[i + 1][1] = ((dp[i][0] - (fibo_2 * a[i]))+MOD)%MOD;
        ll temp = fibo_2;
        fibo_2 = fibo_1%MOD;
        fibo_1 = (fibo_1+temp)%MOD;
    }

    cout << (dp[n][0] + dp[n][1] + 2*MOD) % MOD << endl;

}
