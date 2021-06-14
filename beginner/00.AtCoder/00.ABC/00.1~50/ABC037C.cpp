#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;

    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];

    for (int i = 0; i <= n-k; ++i) {
        ans += sum[i+k] - sum[i];
    }
    cout << ans << endl;
}
