#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    vector<ll> vec(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            vec[j]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i*vec[i];
    }

    cout << ans << endl;
    return 0;
}
