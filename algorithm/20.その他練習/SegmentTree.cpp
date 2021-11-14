/**
 * セグメント木に遅延セグメント木の機能を追加したもの 
 * いろいろ参考にしてきたから機能が重複する関数あるかも
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000007;

struct SegmentTree {
    private:
        int n;
        vector<int> node;
        vector<int> lazy;

    public:
        SegmentTree(vector<int> v) {
            int sz = v.size();
            n = 1;
            while(n < sz) n *= 2;
            node.resize(2*n-1, INF);

            for (int i = 0; i < n; ++i) node[n+i-1] = v[i];
            for (int i = n-2; i >= 0; --i) node[i] = min(node[2*i+1], node[2*i+2]); 
        }

        void update(int x, int val) {
            x += n-1;
            node[x] = val;
            while (x > 0) {
                x = (x-1)/2;
                node[x] = min(node[2*x+1], node[2*x+2]);
            }
        }

        void update_range(int a, int b, int x, int k, int l, int r) {
            push(k);
        }

        /**
         * 要求区間の最小値を対象区間の中から見つける
         * 要求区間：[a, b)
         * 対象区間：[l, r)
         */

        int getmin(int a, int b, int k=0, int l=0, int r = -1) {
            if (r < 0) r = n;

            // 要求区間と対象区間が交わらない場合 
            if (r <= a || b <= l) return INF;

            // 要求区間が対象区間を完全に覆っている場合
            if (a <= l && r <= b) return node[k];

            // 要求区間の一部が対象区間と交わっている場合
            // 半分に分割して再帰的に最小値を求める。
            int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
            int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
            return min(vl, vr);
        }
};