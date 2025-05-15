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
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    int a = 0, b = 0;
    rep(i, 0, n) a += x[i];
    rep(i, 0, n) b += y[i];

    if (a == b) cout << "Draw" << endl;
    else if (a > b) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
