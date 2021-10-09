#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll x;
    cin >> x;

    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    ll ans = 0;
    ll div = x/sum;
    ans = div * n;
    x %= sum;

    for (int i = 0; i < n; ++i) {
        if (x < a[i]) {
            ans++;
            break;
        } else {
            ans++;
            x -= a[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
