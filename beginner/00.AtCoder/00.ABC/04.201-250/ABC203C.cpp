#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll> > a(n+1);
    a[0].first = 0; a[0].second = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i+1].first - a[i].first <= k) {
            ans += a[i+1].first - a[i].first;
            k = k + a[i+1].second - (a[i+1].first - a[i].first);
        } else if (a[i+1].first - a[i].first > k) {
            ans += k;
            cout << ans << endl;
            return 0;
        } 
    }
    ans += k;
    cout << ans << endl;
    return 0;
}
