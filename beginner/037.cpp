#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

struct SegmentTree {
    int n;
    vector<int> node;

    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n, INF);
        for(int i = 0; i < sz; ++i) node[i+n-1] = v[i];
        for(int i = n-2; i >= 0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n-1);
        node[x] = val;
        while(x > 0) {
            x = (x-1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k = 0, int l=0, int r=-1) {
        if (r < 0) r = n;
        if (r <= a || b <= 1) return INF;
        if (a <= 1 && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main()
{
    int w, n;
    cin >> w >> n;
    vector<int> l(n), r(n), v(n);

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i] >> v[i];


}
