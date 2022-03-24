#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int range = 10100;
const ll infl = 1LL << 60;

struct SegmentTree {
private:
    int n = 1;
    vector<ll> node;

public:
    void init(int sz) {
        while(n < sz) n *= 2;
        node.resize(2*n-1, -infl);
    }

    void update(int x, int val) {
        x += n-1;
        node[x] = val;
        while(x > 0) {
            x = (x-1)/2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmax(int x, int y, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = n;

        if (r <= x || y <= l) return 0;

        if (x <= l && r <= y) return node[k];

        int vl = getmax(x, y, 2*k+1, l, (r+l)/2);
        int vr = getmax(x, y, 2*k+2, (r+l)/2, r);
        return vl + vr;
    }
};

SegmentTree seg[510];
ll dp[510][20000];
ll w, n;

int main()
{
    cin >> w >> n;
    vector<ll> l(n+1), r(n+1), v(n+1);
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i] >> v[i];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) dp[i][j] = -infl;
        seg[i].init(w+2);
    }
    dp[0][0] = 0;
    seg[0].update(0, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) dp[i][j] = dp[i-1][j];
        for (int j = 0; j <= w; ++j) {
            int cl = max(0, j - (int)r[i]), cr = max(0, j - (int)l[i]+1);
            if (cl == cr) continue;
            ll val = seg[i-1].getmax(cl, cr, 0, 0, n);
            if (val != -infl) {
                dp[i][j] = max(dp[i][j], val+v[i]);
            }
        }
        for (int j = 0; j <= w; ++j) seg[i].update(j, dp[i][j]);
    }

    if (dp[n][w] == -infl) cout << -1 << endl;
    else cout << dp[n][w] << endl;
    return 0;
}
