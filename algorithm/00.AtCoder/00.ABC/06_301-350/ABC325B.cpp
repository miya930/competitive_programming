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
    vector<int> w(n), x(n);
    rep(i, 0, n) cin >> w[i] >> x[i];

    int ans = 0;
    rep(i, 0, 24) {

        int sum = 0;
        rep(j, 0, n) {
            int cur = (x[j] + i) % 24;
            if (cur >= 9 && cur < 18) {
                sum += w[j];
            }
        }
        ans = max(sum, ans);
    }
    cout << ans << endl;

    return 0;
}
