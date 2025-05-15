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
    int t;
    cin >> t;

    for (int xx = 0; xx < t; xx++) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<ll,int>> c(n);
        for (int i = 0; i < n; i++) {
            c[i].first = a[i];
            c[i].second = b[i];
        }
        sort(c.begin(), c.end());
        ll ma = 0, sum = 0;
        priority_queue<int> que;
        for (int i = 0; i < k; i++) {
            que.push(c[i].second);
            ma = max(ma, c[i].first);
            sum += c[i].second;
        }
        ll ans = infl;
        ans = min(ans, ma * sum);

        for (int i = k; i < n; i++) {
            ll po = que.top();
            if (po > c[i].second) {
                que.pop();
                que.push(c[i].second);
                sum -= po;
                sum += c[i].second;
            }
            ma = c[i].first;
            ans = min(ans, ma * sum);
        }
        cout << ans << endl;
    }


    return 0;
}
