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
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    rep(i, 0, n) {
        rep(j, i+1, n+1) {
            string str;
            rep(k, i, j) {
                str.push_back(s[k]);
            }
            int m = str.size();
            bool ok = true;
            rep(k, 0, m) {
                if (str[k] != str[m-k-1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = max(ans, j - i);
        }
    }
    cout << ans << endl;

    return 0;
}
