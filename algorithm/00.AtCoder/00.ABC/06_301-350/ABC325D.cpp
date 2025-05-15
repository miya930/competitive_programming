#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> pa(n);
    rep(i, 0, n) {
        cin >> pa[i].first >> pa[i].second;
        pa[i].second += pa[i].first;
    }
    sort(pa.begin(), pa.end());

    ll t = pa[0].first;
    int idx = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.push(pa[idx].second);
    int ans = 0;
    idx++;
    while(1) {
        // 可能時間以上のものを取り出す
        while(t >= pa[idx].first && idx < n) {
            ll po = pa[idx].second;
            que.push(po);
            idx++;
        }

        if (que.empty()) {
            ll po = pa[idx].second;
            t = pa[idx].first;
            que.push(po);
            idx++;
        }

        ll nxt = que.top();
        que.pop();
        if (t <= nxt) {
            t += 1;
            ans++;
        } else {
            // 過ぎてしまったものを削除
            while(1) {
                nxt = que.top();
                if (t <= nxt || que.empty()) break; 
                que.pop();
            }
        }

        if (idx >= n && que.empty()) break;

    }

    cout << ans << endl;

    return 0;
}
