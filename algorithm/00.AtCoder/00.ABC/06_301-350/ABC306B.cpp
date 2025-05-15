#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<ll> a(64);
    for (int i = 0; i < 64; i++) cin >> a[i];
    unsigned long long cur = 1;
    unsigned long long ans = 0;
    for (int i = 0; i < 64; i++) {
        if (a[i] == 1) ans += cur;
        cur *= 2LL;
    }
    cout << ans << endl;
    return 0;
}
