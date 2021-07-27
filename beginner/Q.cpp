#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

struct SegmentTree {
private:
    int n;
    vector<int> node;
    
public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.assign(n, INF);
        
        for (int i = 0; i < n; ++i) node[i+n-1] = v[i];
        for (int i = n-2; i >= 0; --i) node[i] = min(v[2*i+1], v[2*i+2]);
    }

    void Update(int x, int val) {
        x += n-1;
        node[x] = val;

        while (x > 0) {
            x = (x-1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;

        if (b <= l || r <= a) return INF;

        if (a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

    int getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
}

int n;
SegmentTree dp(n+1);

int main()
{
    cin >> n;
    vector<long long> h(n), a(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        long long opt = dp.get(0, h[i]) + a[i];;
        dp.update(h[i], max(dp[h[i]], opt));
    }

    cout << dp.getmax(0, INF);
}
