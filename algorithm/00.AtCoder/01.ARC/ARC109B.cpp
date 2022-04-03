#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

bool check(ll key) {
    ll tmp = key*(key+1)/2;
    if (tmp > n+1LL) return true;
    else return false;
}

int main()
{
    cin >> n;

    ll l = 0, r = (ll)2e9+1;
    while(r-l > 1LL) {
        ll mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << n - r + 2LL << endl;
    return 0;
}
