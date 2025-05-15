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
    string s;
    cin >> n >> m >> s;

    int muji = 0;
    int rogo = 0;
    int ans = 0;
    rep(i, 0, n) {
        if (s[i] == '1') {
            muji++;
        } else if (s[i] == '2') {
            rogo++;
        } else {
            ans = max(ans, rogo + max(muji - m, 0));
            muji = 0;
            rogo = 0;
        }
    }
    if (muji > 0 || rogo > 0) ans = max(ans, rogo + max(muji - m, 0));
    cout << ans << endl;

    return 0;
}
