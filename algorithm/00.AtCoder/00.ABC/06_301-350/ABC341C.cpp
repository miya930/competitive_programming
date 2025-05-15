#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    vector<string> s(h);
    cin >> t;
    rep(i, 0, h) cin >> s[i];

    map<char, int> mp;
    mp['L'] = 3;
    mp['R'] = 1;
    mp['U'] = 2;
    mp['D'] = 0;

    int ans = 0;
    rep(i, 0, h) {
        rep(j, 0, w) {
            if (s[i][j] == '#') continue;
            int vx = i;
            int vy = j;
            bool isok = true;
            rep(l, 0, n) {
                int idx = mp[t[l]];
                int nx = vx + dx[idx];
                int ny = vy + dy[idx];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || s[nx][ny] == '#') {
                    isok = false;
                    break;
                }
                vx = nx;
                vy = ny;
            }
            if (isok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
