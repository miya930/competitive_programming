//https://atcoder.jp/contests/nikkei2019-final/submissions/me

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    long long ans;
    for (int k = 1; k <= n; ++k) {
        ans = 0;
        for (int i = 0; i <= n-k; ++i) {
            ans = max(ans, sum[i+k] - sum[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
