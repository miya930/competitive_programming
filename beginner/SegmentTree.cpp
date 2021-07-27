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
		n = 1; while (n < sz) n *= 2;
        node.resize(2*n-1, INF);

        for (int i = 0; i < sz; ++i) node[i+n-1] = v[i];                            // 最下段のn項を埋めていく
        for (int i = n - 2; i >= 0; --i) node[i] = min(node[2*i+1], node[2*2+2]);   // 最下段より上の段を下から順番に埋めていく
	}

    void update(int x, int val) {
        x += (n-1);

        node[x] = val;
        while (x > 0) {
            x = (x-1) / 2;
            node[x] = min(code[2*x+1], code[2*x+2]);
        }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    // 対象区間は [l, r) にあたる

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        // 最初に呼び出されたときの対象区間は [0, n)
        if (r < 0) r = n;

        if (r <= a || b <= l) return INF;

        if (a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
