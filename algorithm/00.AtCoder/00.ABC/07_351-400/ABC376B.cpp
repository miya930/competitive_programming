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
    int n, Q;
    cin >> n >> Q;
    int l = 0, r = 1;

    int ans = 0;
    for (int q = 0; q < Q; q++) {
        char h;
        int t;
        cin >> h >> t;
        t--;
        if (h == 'R') {
            if (t == r) continue;
            // 時計周り
            int cur = r;
            int cnt = 0;
            bool ng = false;
            while(1){
                cur++;
                cur %= (n);
                cnt++;
                if (cur == t) break;
                else if (cur == l) {
                    ng = true;
                    break;
                }
            }
            if (!ng) {
                ans += cnt;
                r = cur;
                continue;
            }

            cur = r;
            cnt = 0;
            ng = false;
            while(1){
                cur--;
                cur = (cur+n) % n;
                cnt++;
                if (cur == t) break;
                else if (cur == l) {
                    ng = true;
                    break;
                }
            } 
            r = cur;
            ans += cnt;           
        } else {
            if (t == l) continue;
            int cur = l;
            int cnt = 0;
            bool ng = false;
            while(1){
                cur++;
                cur %= n;
                cnt++;
                if (cur == t) break;
                else if (cur == r) {
                    ng = true;
                    break;
                }
            }
            if (!ng) {
                ans += cnt;
                l = cur;
                continue;
            }
            cur = l;
            cnt = 0;
            ng = false;
            while(1){
                cur--;
                cur = (cur + n) % n;
                cnt++;
                if (cur == t) break;
                else if (cur == l) {
                    ng = true;
                    break;
                }
            } 
            ans += cnt; 
            l = cur;
        }
    }
    cout << ans << endl;
    return 0;
}
