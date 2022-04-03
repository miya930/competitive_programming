#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    priority_queue<ll> que;
    for (int i = 0; i < n; ++i) que.push(a[i]);

    while(!que.empty() && k > 0) {
        ll v = que.top();
        que.pop();
        if (v >= x) {
            int cnt = v/x;
            if (k < cnt) {
                cnt = k;
                k = 0;
            } else k -= cnt;
            v -= (cnt*x);
            que.push(v);
        } else {
            k--;
        }
    }

    ll ans = 0;
    while(!que.empty()) {
        ll v = que.top();
        que.pop();
        ans += v;
    }

    cout << ans << endl;
    return 0;
}
