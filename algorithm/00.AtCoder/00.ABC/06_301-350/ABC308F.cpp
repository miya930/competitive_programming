#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool gre(pair<ll,ll> lhs, pair<ll,ll> rhs) {
    if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
    } else {
        return lhs.second > rhs.second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> p(n), l(m), d(m);
    vector<pair<ll,ll>> pa(m);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> l[i];
    for (int i = 0; i < m; i++) cin >> d[i];
    for (int i = 0; i < m; i++) {
        pa[i].first = l[i];
        pa[i].second = d[i];
    }
    sort(pa.begin(), pa.end(), gre);
    sort(p.begin(), p.end());

    int cur = 0;
    priority_queue<ll> que;
    for (int i = 0; i < n; i++) {
        while(cur < m && p[i] >= pa[cur].first) {
            que.push(pa[cur].second);
            cur++;
        }
        if (!que.empty()) {
            ll val = que.top();
            que.pop();

            p[i] -= val;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p[i];
    }
    cout << ans << endl;
    return 0;
}
