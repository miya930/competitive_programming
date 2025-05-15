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
    string t;
    cin >> n >> t;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    vector<int> ans;
    rep(i, 0, n) {
        if (t.size() == s[i].size()) {
            int cnt = 0;
            rep(j, 0, (int)t.size()) {
                if (t[j] != s[i][j]) cnt++;
            }
            if (cnt < 2) {
                ans.push_back(i+1);
            }
        } else if (t.size() == s[i].size()+1) { // 削除した場合
            int curt = 0, curs = 0;
            int cnt = 0;
            while(1) {
                if (t[curt] != s[i][curs]) {
                    cnt++;
                    curt++;
                } else {
                    curt++;
                    curs++;
                }
                if (curt == (int)t.size() && (curs == (int)s[i].size())) {
                    ans.push_back(i+1);
                    break;
                }
                if (cnt > 1) break;
            }
        } else if ((t.size() + 1) == s[i].size()) {
            int curt = 0, curs = 0;
            int cnt = 0;
            while(1) {
                if (t[curt] != s[i][curs]) {
                    cnt++;
                    curs++;
                } else {
                    curt++;
                    curs++;
                }
                if (curt == (int)t.size() && curs == (int)s[i].size()) {
                    ans.push_back(i+1);
                    break;
                }
                if (cnt > 1) break;
            }            
        }
    }

    cout << ans.size() << endl;
    rep(i, 0, (int)ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
