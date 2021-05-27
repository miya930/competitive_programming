#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> s(n+1, 0), t(n+1, 0), ma(n+1,0);
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + a[i];

    for (int i = 0; i < n; ++i) {
        t[i+1] = s[i+1] + t[i];
    }

    ll max_i = 0;
    for (int i = 1; i <= n; ++i) {
        max_i = max(max_i, a[i-1]);
        cout << t[i] + i*max_i << endl; 
    }
}
