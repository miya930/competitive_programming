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

        for (int i = 0; i < sz; ++i) node[i+n-1] = v[i];                            // �ŉ��i��n���𖄂߂Ă���
        for (int i = n - 2; i >= 0; --i) node[i] = min(node[2*i+1], node[2*2+2]);   // �ŉ��i����̒i�������珇�Ԃɖ��߂Ă���
	}

    void update(int x, int val) {
        x += (n-1);

        node[x] = val;
        while (x > 0) {
            x = (x-1) / 2;
            node[x] = min(code[2*x+1], code[2*x+2]);
        }
    }

    // �v����� [a, b) ���̗v�f�̍ŏ��l�𓚂���
    // k := ����������m�[�h�̃C���f�b�N�X
    // �Ώۋ�Ԃ� [l, r) �ɂ�����

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        // �ŏ��ɌĂяo���ꂽ�Ƃ��̑Ώۋ�Ԃ� [0, n)
        if (r < 0) r = n;

        if (r <= a || b <= l) return INF;

        if (a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};
