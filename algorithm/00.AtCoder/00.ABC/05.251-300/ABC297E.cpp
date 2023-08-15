#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> ans(k+1, 0);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.push(0);
    
    int cur = 0;

    while(cur < k+1) {
        ll v = que.top();
        que.pop();

        if (cur > 0) {
            if (ans[cur-1] == v) continue;
        }

        ans[cur] = v;
        for (int i = 0; i < n; i++) {
            que.push(v+a[i]);
        }
        cur++;
    }

    cout << ans[k] << endl;
    return 0;
}
