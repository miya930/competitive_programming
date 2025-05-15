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
    int cnt = 0;
    int n = s.size();
    reverse(s.begin(), s.end());
    string ans = "";
    rep(i, 0, n){
        if (s[i] == '.') break;
        ans += s[i];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
