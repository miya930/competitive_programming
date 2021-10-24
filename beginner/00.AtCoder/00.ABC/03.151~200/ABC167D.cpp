/**
   created: 23.10.2021 09:25:13
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    ll cycle = 0;
    ll now = 0;
    vector<bool> seen(n, false);
    while (!seen[now]) {
        seen[now] = true;
        now = a[now];
        cycle++;
    }

    ll p = 0, c = 0;;
    for (int i = 0; i < n; ++i) {
        if (p == now) {
            break;
        } else {
            p = a[p];
            c++;
        }
    }

    cycle -= c;

    ll pos = 0;
    if (k < c) {
        while (k > 0) {
            k--;
            pos = a[pos];
        }
        cout << pos+1 << endl;
    } else {
        k -= c;
        k %= cycle;
        while (k > 0) { 
            k--;
            now = a[now];
        }
        cout << now+1 << endl;
    }

    return 0;
}
