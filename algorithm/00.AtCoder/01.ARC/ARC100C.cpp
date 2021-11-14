#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> b = a;
    for (int i = 0; i < n; ++i) b[i] = a[i] - (i+1);

    sort(b.begin(), b.end());

    ll median = b[n/2];
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += abs(b[i]-median);

    cout << ans << endl;

    return 0;
}
