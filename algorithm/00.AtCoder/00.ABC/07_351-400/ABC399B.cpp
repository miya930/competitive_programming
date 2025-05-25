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
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];

    int r = 1;
    vector<int> order(n, -1);
    while(true) {
        int ma = 0;
        int cnt = 0;
        rep(i, 0, n) {
            if (order[i] == -1) {
                if (ma < p[i]) {
                    cnt = 1;
                    ma = p[i];
                } else if (ma == p[i]) {
                    cnt++;
                }
            }
        }
        rep(i, 0, n) {
            if (p[i] == ma) order[i] = r;
        }
        r += cnt;
        bool finish = true;
        rep(i, 0, n) {
            if (order[i] == -1) finish = false;
        }
        if (finish) break;
    }
    rep(i, 0, n) cout << order[i] << endl;

    return 0;
}
