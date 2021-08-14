#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

struct LazySegmentTree {
    private:
        int n;
        vector<ll> node, lazy;
    
    public:
        LazySegmentTree(vector<ll> v) {
            int sz = (int)v.size();
            n = 1; while(n < sz) n *= 2;
            node.resize(2*n-1);
            lazy.resize(2*n-1, 0);
            
            for (int i = 0; i < sz; ++i) node[n-1+i] = v[i];
            for (int i = n-2; i >= 0; --i) node[i] = min(node[2*i+1], node[2*i+2]);
        }

        void eval(int k, int l, int r) {
            
            if (lazy[k] != 0) {
                node[k] += lazy[k];

                if (r-l > 1) {
                    lazy[2*k+1] += lazy[k]/2;
                    lazy[2*k+2] += lazy[k]/2;
                }

                lazy[k] = 0;
            }
        }

        // 行きがけ順に子ノードに配分していき、帰りがけ順にnodeを更新していく
        void add(int a, int b, int x, int k=0, int l=0, int r=-1) {
            if (r < 0) r = n;

            eval(k, l, r);

            if (b <= l || r <= a) return;

            if (a <= l && r <= b) {
                lazy[k] += (r-l) * x;
                eval(k, l, r);
            } else {
                add(a, b, x, 2*k+1, l, (l+r)/2);
                add(a, b, x, 2*k+2, (l+r)/2, r);
                node[k] = node[2*k+1] + node[2*k+2];
            }
        }
};
