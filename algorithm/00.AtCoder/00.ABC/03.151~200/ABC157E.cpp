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

template<class T, int nv> struct SegTree {
    T comp(T& l, T& r) {
        return l | r;
    }

    vector<T> val;
    SegTree() {
        val = vector<T>(nv * 2, 0);
    }
    T get(int x, int y, int l = 0, int r = nv, int k = 1) {
        if (r <= x || y <= l) return 0;
        if (x <= l && r <= y) return val[k];
        auto a = get(x, y, l, (l+r)/2, k * 2);
        auto b = get(x, y, (l+r)/2, r, k*2 + 1);
        return comp(a, b);
    }
    void update(int i, T v) {
        i += nv;
        val[i] = v;
        while(i > 1) {
            i >>= 1;
            val[i] = comp(val[2*i], val[2*i+1]);
        }
    }
};

SegTree<ll, 1 << 19> sg;

int main()
{
    int n, Q;
    string s;
    cin >> n >> s >> Q;
    rep(i, 0, n) {
        sg.update(i, 1LL<<(s[i]-'a'));
    }
    rep(q, 0, Q) {
        int t; cin >> t;
        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            sg.update(i, 1LL<<(c-'a'));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            ll mask = sg.get(l, r);
            int ans = __builtin_popcount(mask);
            cout << ans << endl;
        }
    }


    return 0;
}
