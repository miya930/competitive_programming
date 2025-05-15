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
    vector<int> a(n);
    rep(i, 0, m) cin >> a[i];

    vector<int> ans(n, 0);
    int cur = 0;
    rep(i, 0, n) {
        if (i+1 < a[cur]) {
            ans[i] = a[cur] - (i+1);
        } else {
            ans[i] = a[cur] - (i+1);
            cur++;
        }
    }
    rep(i, 0, n) cout << ans[i] << endl;

    return 0;
}
