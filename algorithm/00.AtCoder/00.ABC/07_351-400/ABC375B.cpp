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

double get_dist(ll x, ll y) {
    return sqrt(x*x + y*y);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double ans = 0;
    ans += get_dist(x[0], y[0]);
    for (int i = 0; i < n-1; i++) {
        ans += get_dist(x[i+1] - x[i], y[i+1] - y[i]);
    }
    ans += get_dist(x[n-1], y[n-1]);

    printf("%.10f\n", ans);

    return 0;
}
