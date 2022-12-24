#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll infl = 1LL << 60;
vector<ll> a;
int n, k;

bool check(ll key) {

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (key/a[i]);
    }

    if (sum >= k) return true;
    else return false;
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll l = 0, r = infl;
    while(r - l > 1) {
        ll mid = (r+l)/2;
        if (check(mid)) r = mid;
        else l = mid;
    } 

    cout << r << endl;

    return 0;
}
