#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

class SegmentTree {
private:
    int sz;
    vector<int> seg;
    vector<int> lazy;

    void push(int k) {
        if (k < sz) {
            lazy[2*k] = max(lazy[2*k], lazy[k]);
            lazy[2*k+1] = max(lazy[2*k+1], lazy[k]);
        }
        seg[k] = max(seg[k], lazy[k]);
        lazy[k] = 0;
    }

    void update(int a, int b, int x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            push(k);
            return;
        }
        update(a, b, x, 2*k, l, (l+r)/2);
        update(a, b, x, 2*k+1, (l+r)/2, r);
        seg[k] = max(seg[k*2], seg[k*2+1]);
    }
    
    int range_max(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return seg[k];

        int lc = range_max(a, b, k*2, l, (l+r)/2);
        int rc = range_max(a, b, k*2+1, (l+r)/2, r);
        return max(lc, rc);
    }

public:
    SegmentTree() : sz(0), seg(), lazy() {};
    SegmentTree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2*sz, 0);
        lazy.resize(2*sz, 0);
    }
    
    void update(int l, int r, int x) {
        update(l, r, x, 1, 0, sz);
    }
    
    int range_max(int l, int r) {
        return range_max(l, r, 1, 0, sz);
    }
};

int main()
{
    int w, n;
    cin >> w >> n;
    SegmentTree seg(w);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        int height = seg.range_max(l-1, r) + 1;
        seg.update(l-1, r, height);
        cout << height << endl;
    }
    return 0;
}
