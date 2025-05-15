#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

int op(int a, int b) { return (a+b); }
int e() { return 0; }

int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    
    segtree<int, op, e> seg(n+1);
    for (int i = 0; i < n; i++) {
        if (s[i] != s[i+1]) seg.set(i+1, 1);
    }
    for (int i = 0; i < q; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            seg.set(l-1, 1-seg.get(l-1));
            seg.set(r, 1-seg.get(r));
        } else {
            if (seg.prod(l, r) == (r-l)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
