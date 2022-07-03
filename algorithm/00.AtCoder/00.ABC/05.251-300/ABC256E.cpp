#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

priority_queue<P, vector<P>, greater<P>> que;
vector<vector<int>> vec(200100);

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), c(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        x[i]--;
        vec[i].push_back(x[i]);
    }

    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cost[x[i]] += c[i];
    
    for (int i = 0; i < n; ++i) que.push(P(cost[i], i));

    ll ans = 0;
    int cnt = 0;
    vector<bool> seen(n, false);
    while(cnt < n) {
        int idx = que.top().second;
        ll co = que.top().first;
        que.pop();
        
        if (seen[idx]) continue;

        ans += co;
        seen[idx] = true;
        cnt++;

        for (auto xx : vec[idx]) {
            cost[xx] -= c[idx];
            que.push(P(cost[xx], xx));
        }
    }

    cout << ans << endl;
    return 0;
}
