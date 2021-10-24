/**
   created: 18.10.2021 23:10:17
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        for (int i = 0; i < sz; ++i) node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; i--) node[i] = node[2*i+1] ^ node[2*i+2];
    }

    void update(int x, int val) {
        x += (n-1);

        node[x] ^= val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = node[2*x+1] ^ node[2*x+2];
        }
    }

    int get(int a, int b, int k=0, int l=0, int r=-1) {
        if (r < 0) r = n;

        if (r <= a || b <= l) return 0;

        if (a <= l && r <= b) return node[k];

        int vl = get(a, b, 2*k+1, l, (l+r)/2);
        int vr = get(a, b, 2*k+2, (l+r)/2, r);
        return (vl ^ vr); 
    }

    int getmem(int x) {
        return node[x];
    }

    int getnum(void) {
        return n;
    }

};

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0 ;i < n;++i) cin >> a[i];

    SegmentTree st(a);
    int m = st.getnum();

    for (int q = 0; q < Q; ++q) {
        int t, x, y;
        cin >> t >> x >> y;
        x--;

        if (t == 1) st.update(x, y);
        else {
            y--;
            cout << st.get(x, y+1, 0, 0, m) << endl;
        }
    }

    return 0;
}
