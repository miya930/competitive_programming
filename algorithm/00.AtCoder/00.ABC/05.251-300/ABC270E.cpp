#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) que.push(a[i]);
    }

    ll dec = 0;
    while(k > 0) {
        ll val = que.top() - dec;
        ll sz = que.size();
        que.pop();

        ll t = val * sz;
        if (t <= k) {
            k -= t;
            dec += val;
            if (k == 0) {
                for (int i = 0; i < n; i++) {
                    a[i] = max(0LL, a[i] - dec);
                }
            }
        } else {
            ll div = k / sz;
            ll mod = k % sz;
            dec += div;
            ll cnt = 0;
            int idx = 0;
            for (int i = 0; i < n; i++) {
                a[i] = max(0LL, a[i] - dec);
            }
            while(cnt < mod) {
                if (a[idx] != 0) {
                    a[idx]--;
                    cnt++;
                } 
                idx++;
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}
