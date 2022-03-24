#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> q[101010];

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < n; ++i) q[a[i]].push_back(b[i]);
    priority_queue<int> que;
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (auto nv : q[i]) que.push(nv);
        if (!que.empty()) {
            ans += que.top();
            que.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
