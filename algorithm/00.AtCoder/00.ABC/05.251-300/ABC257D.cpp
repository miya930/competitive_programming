#include <bits/stdc++.h>
using namespace std;
using ll = long long;

queue<pair<int,pair<ll, ll>>> que;
vector<pair<ll,ll>> pos;
vector<ll> po;
vector<bool> seen;

int n;

bool bfs(int e, ll mid) {
    que.push(make_pair(e, make_pair(pos[e].first, pos[e].second)));
    seen.assign(n, false);
    int cnt = 1;

    seen[e] = true;

    while(!que.empty()) {
        int v  = que.front().first;
        int vx = que.front().second.first;
        int vy = que.front().second.second;
        ll  ps = po[v] * mid;
        que.pop();

        for (int i = 0; i < n; i++) {
            if (i == v) continue;
            if (seen[i] == true) continue;
            ll nx = pos[i].first;
            ll ny = pos[i].second;
            ll diff = abs(nx - vx) + abs(ny - vy);

            if (diff > ps) continue;

            que.push(make_pair(i, make_pair(nx, ny)));
            seen[i] = true;
            cnt++;
        }
    }

    if (cnt == n) return true;
    else return false;
}

bool check(ll mid) {
    bool ret = false;
    for (int i = 0; i < n; ++i) {
        ret = ret | bfs(i, mid);
    }

    return ret;
}

int main()
{
    cin >> n;
    pos.resize(n);
    po.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> pos[i].first >> pos[i].second >> po[i];
    }

    ll l = -1, r = 4000000001LL;
    while(r - l > 1) {
        ll mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}
