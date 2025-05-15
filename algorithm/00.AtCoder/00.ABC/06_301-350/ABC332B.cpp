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
    int k, g, m;
    cin >> k >> g >> m;

    int gn = 0, mn = 0;
    rep(i, 0, k) {
        if (gn == g) {
            gn = 0;
        } else if (mn == 0) {
            mn = m;
        } else {
            int mov = min(g - gn, mn);
            gn += mov;
            mn -= mov;
        }
    }
    cout << gn << " " << mn << endl;
    return 0;
}
