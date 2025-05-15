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
    int n, x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i, 0, n-1) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = inf;
    rep(i, 0, 101) {
        vector<int> b = a;
        b.push_back(i);
        sort(b.begin(), b.end());
        int sum = 0;
        rep(j, 1, n-1) {
            sum += b[j];
        }
        if (sum >= x) {
            cout << i << endl;
            return 0;
        }
    } 

    cout << -1 << endl;

    return 0;
}
