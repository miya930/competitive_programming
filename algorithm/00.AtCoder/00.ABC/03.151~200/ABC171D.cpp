#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) mp[a[i]]++;

    ll ans = 0;

    for (int i = 0; i < n; ++i) ans += a[i];
      
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        ll b, c;
        cin >> b >> c;
        ll tmp = mp[b];
        mp[b] = 0;
        mp[c] += tmp;
        
        ans -= b * tmp;
        ans += c * tmp;
        cout << ans << endl;
    }
}
