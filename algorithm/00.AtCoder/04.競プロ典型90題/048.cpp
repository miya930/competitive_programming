/**
  * 
  * ã£ÉvÉçìTå^90ñ‚
  * 048 - I will not drop out
  * link : https://atcoder.jp/contests/typical90/tasks/typical90_av
  * 
  */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<int> c(2*n+2,0);
    for (int i = 0; i < n; i++) {
        c[i] = b[i];
        c[i+n] = a[i] - b[i];
    }
    sort(c.rbegin(), c.rend());

    ll ans = 0;
    for (int i = 0; i < k; ++i) ans += c[i];
    cout << ans << endl;
}
