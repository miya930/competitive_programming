#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i< n; ++i) ans += (a[i]-1);

    cout << ans << endl;
    return 0;
}
