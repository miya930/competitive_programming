#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int mod = 100;

    int ans = 0;
    for (int i = 0; i < n; ++i) ans += a[i];

    cout << ans % mod << endl;

    return 0;
}
