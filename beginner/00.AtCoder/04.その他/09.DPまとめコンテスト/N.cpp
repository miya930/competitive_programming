#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1LL << 60;

vector<vector<long long> > dp;
vector<long long> sum;

long long func(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];

    if (l == r) return 0;

    long long res = inf;
    for (int m = l; m < r; ++m) res = min(res, func(l, m)+func(m+1, r));
    return dp[l][r] = res + sum[r+1] - sum[l];
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp.assign(500, vector<long long>(500, -1));
    sum.assign(500, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i]; 

    cout << func(0, n-1) << endl;
}
