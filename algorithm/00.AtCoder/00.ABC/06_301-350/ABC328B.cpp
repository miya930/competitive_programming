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
    vector<int> d(n+1);
    rep(i, 1, n+1) cin >> d[i];

    int sum = 0;
    rep(i, 1, n+1) {
        rep(j, 1, d[i]+1) {
            int dd = j;
            int mm = i;
            if (mm < 10) {
                if (dd < 10) {
                    if (i == dd) {
                        sum++;
                    }
                } else if (dd < 100) {
                    int v = dd%10;
                    dd /= 10;
                    int vv = dd%10;
                    if (i == v && v == vv) sum++;
                }
            } else {
                int s = mm%10;
                mm /= 10;
                int t = mm%10;
                if (dd < 10) {
                    if (s == dd && dd == t) {
                        sum++;
                    }
                } else if (dd < 100) {
                    int v = dd%10;
                    dd /= 10;
                    int vv = dd%10;
                    if (s == v && v == vv && s == t) sum++;
                }

            }
        }
    }
    cout << sum << endl;
    return 0;
}
