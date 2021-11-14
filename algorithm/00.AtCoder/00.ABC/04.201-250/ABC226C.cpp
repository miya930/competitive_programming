#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> T(n), K(n);
    vector<vector<ll>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> K[i];
        for (int j = 0; j < K[i]; ++j) {
            int tmp; cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }

    vector<int> cnt;
    vector<bool> seen(n, false);
    queue<int> que;
    que.push(n-1);
    while (!que.empty()) {
        int x = que.front();
        que.pop();

        if (seen[x]) continue;
        seen[x] = true;

        for (auto v : a[x]) {
            cnt.push_back(v);
            que.push(v);
        }
    } 
    
    sort(cnt.begin(), cnt.end());
    seen.assign(n, false);
    ll ans = T[n-1];
    for (int i = 0; i < cnt.size(); ++i) {
        if (seen[cnt[i]]) continue;
        seen[cnt[i]] = true;
        ans += T[cnt[i]];
    }
    cout << ans << endl;
    return 0;
}
