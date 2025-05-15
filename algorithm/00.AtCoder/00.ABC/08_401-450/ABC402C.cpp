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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    map<int,int> mp;
    map<int, vector<int>> dis;
    rep(i, 0, m) {
        int k; cin >> k;
        a[i].resize(k, 0);
        rep(j, 0, k) {
            cin >> a[i][j];
            mp[i]++;
            dis[a[i][j]].push_back(i);
        }
    }
    int eatable = 0;

    rep(i, 0, n) {
        int b;
        cin >> b;
        vector<int> v = dis[b];
        int si = v.size();
        for (int j = 0; j < si; j++) {
            mp[v[j]]--;
            if(mp[v[j]] <= 0) eatable++;
        }

        cout << eatable << endl;
    }

    return 0;
}
