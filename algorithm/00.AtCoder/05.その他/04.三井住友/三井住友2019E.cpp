/**
   created: 09.10.2021 15:50:01
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll cnt = 3;

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ans *= cnt;
            cnt--;
            vec[a[i]]++;
        }
        else {
            ans *= (vec[a[i]-1] - vec[a[i]]);
            ans %= mod;
            vec[a[i]]++;
        }
    }    

    cout << ans << endl;

    return 0;
}
