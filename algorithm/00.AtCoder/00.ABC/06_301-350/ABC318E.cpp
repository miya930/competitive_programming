#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);

    ll ans = 0;
    for (auto v : mp) {
        int nv = v.first;
        vector<int> vec = v.second;
        int si = vec.size();
        if (si == 1) continue;
        for (ll i = 0; i < si-1; i++) {
            ans = ans + (vec[i+1]-vec[i]-1)*(i+1)*(si-i-1);
        }
    }
    cout << ans << endl;
    return 0;
}
