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
    int t;
    cin >> t;
    rep(_, 0, t) {
        int n;
        cin >> n;
        vector<int> a(2*n);
        vector<vector<int>> pos(n+1);
        rep(i, 0, 2*n) cin >> a[i];
        rep(i, 0, 2*n) {
            pos[a[i]].push_back(i);
        }

        set<pair<int,int>> ans;
        rep(i, 0, 2*n-1) {
            int u = a[i], v = a[i+1];
            if (pos[u][0]+1 == pos[u][1]) continue;
            if (pos[v][0]+1 == pos[v][1]) continue;
            vector<int> vec;
            vec.push_back(pos[u][0]);
            vec.push_back(pos[u][1]);
            vec.push_back(pos[v][0]);
            vec.push_back(pos[v][1]);
            sort(vec.begin(), vec.end());
            if (vec[0] + 1 == vec[1] and vec[2] + 1 == vec[3]) {
                ans.emplace(minmax(u, v));
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}
