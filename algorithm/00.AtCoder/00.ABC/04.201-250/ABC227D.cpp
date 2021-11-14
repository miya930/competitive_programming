#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0 ;i < n; ++i) cin >> a[i];

    ll ok = 0, ng = 1e18 / k;
    while (ng - ok > 1) {
        ll md = (ok+ng)/2, sum = 0;
        for (auto x : a) sum += min(x, md);
        if (sum >= k*md) ok = md;
        else ng = md;  
    }
    cout << ok << endl;
}
