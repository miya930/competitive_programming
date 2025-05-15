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
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n-2; i++) {
        if (s[i] == '#' && s[i+1] == '.' && s[i+2] == '#') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
