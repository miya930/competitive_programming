#include <bits/stdc++.h>
#include <atcoder/all>
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

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

const int A = 500100;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    atcoder::segtree<int, op, e> seg(A);
    for (int e : a) {
        int l = max(0, e - d);
        int r = min(A - 1, e + d);
        int mx = seg.prod(l, r+1);
        seg.set(e, mx+1);
    }

    cout << seg.all_prod() << endl;
    return 0;
}
