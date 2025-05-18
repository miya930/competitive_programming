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
    vector<pair<char, ll>> v;
    
    rep(i, 0, n-1) {
        if (p[i] < p[i+1]) {
            if (v.empty() or v.back().first == '>') v.push_back({'<', 1});
            else v.back().second++;
        } else {
            if (v.empty() or v.back().first == '<') v.push_back({'>', 1});
            else v.back().second++;
        }
    }
    int m = v.size();
    ll ans = 0;
    rep(i, 0, m-2) {
        if (v[i].first == '<') {
            ans += v[i].second * v[i+2].second;
        }
    }
    cout << ans << endl;
}
