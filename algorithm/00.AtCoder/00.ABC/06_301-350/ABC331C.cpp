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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<ll> b = a;
    sort(b.begin(), b.end());
    vector<ll> sum(n+1, 0);
    rep(i, 0, n) {
        sum[i+1] = sum[i] + b[i];
    }
    rep(i, 0, n) {
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << sum[n] - sum[idx] << " ";
    }
    cout << endl;

    return 0;
}
