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
    int n, m;
    cin >> n >> m;
    vector<ll> t(m), w(m), s(m);
    rep(i, 0, m) cin >> t[i] >> w[i] >> s[i];
    vector<ll> ans(n, 0);
    priority_queue<int, vector<int>, greater<int>> deq;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
    rep(i, 0, n) deq.push(i);

    rep(i, 0, m) {
        while(!que.empty()) {
            int las = que.top().first;
            int peo = que.top().second;
            if (las <= t[i]) {
                deq.push(peo);
                que.pop();
            } else {
                break;
            }
        }
        if (deq.empty()) continue;
        int v = deq.top();
        ans[v] += w[i];
        deq.pop();
        que.push(make_pair(t[i]+s[i], v));
    }

    rep(i, 0, n) {
        cout << ans[i] << endl;
    }

    return 0;
}
