#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l -= a[i];
    }

    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < n; ++i) que.push(a[i]);

    if (l > 0) que.push(l);

    while(que.size() > 1) {
        ll u = que.top(); que.pop();
        ll v = que.top(); que.pop();

        ans += (u+v);
        que.push(u+v);
    }

    cout << ans << endl;
    return 0;
}
