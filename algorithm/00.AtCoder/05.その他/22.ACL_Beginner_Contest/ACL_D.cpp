#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;
const int range = 301010;

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree() {
        int sz = range;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
    }

    void update(int x, int val) {
        x += (n-1);

        node[x] = val;
        while(x > 0) {
            x = (x-1)/2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;

        if (r <= a || b <= l) return 0;

        if (a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (r+l)/2);
        int vr = getmax(a, b, 2*k+2, (r+l)/2, r);
        return max(vl, vr);
    }

};

int n,k;
vector<int> a;
SegmentTree seg;

int main()
{
    
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

   
    for (int i = 0; i < n; ++i) {
        int ma = seg.getmax(max(0, a[i]-k), min(range, a[i]+k+1));
        seg.update(a[i], ma+1);
    }

    int ans = seg.getmax(0, range);
    cout << ans << endl;

    return 0;
}
