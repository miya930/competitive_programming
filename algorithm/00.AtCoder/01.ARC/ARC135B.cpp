#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll n;
    cin >> n;
    vector<ll> s(n), a(n+2);
    for (int i = 0 ; i < n; ++i) cin >> s[i];
    a[0] = 0; a[1] = 0;
    for (int i = 0 ; i < n; ++i) a[i+2] = s[i] - a[i+1] - a[i];
    vector<ll> c(3, infl);
    
    for (int i = 0; i < n+2; ++i) c[i%3] = min(c[i%3], a[i]);

    if (c[0]+c[1]+c[2] < 0) {
        cout <<"No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    c[2] = -c[1] - c[0];
    for (int i = 0; i < n + 2; ++i) a[i] -= c[i%3];
    for (auto x : a) cout << x << " "; 

    return 0;
}
