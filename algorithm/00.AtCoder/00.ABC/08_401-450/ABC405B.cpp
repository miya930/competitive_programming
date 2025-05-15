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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    int ans = 0;
    map<int,int> b;        

    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        if (b.count(i) == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    while(true) {
        ans++;
        a.pop_back();
        map<int,int> b;        

        for (int i = 0; i < a.size(); i++) {
            b[a[i]]++;
        }
        bool exist = true;
        for (int i = 1; i <= m; i++) {
            if (b.count(i) == 0) {
                exist = false;
                break;
            }
        }
        if (!exist) break;
    } 
    cout << ans << endl;

    return 0;
}
