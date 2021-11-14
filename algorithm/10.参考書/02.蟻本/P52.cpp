#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, W;

// �i�b�v�T�b�N���̋𒼉� (�ċA�֐����g�p���ĉ���)
int rec(int i, int j) {
    int res;
    if (i == n) {
        // �����i���͎c���Ă��Ȃ�
        res = 0;
    } else if (j < w[i]) {
        // ���̕i���͓���Ȃ�
        res = rec(i + i, j);
    } else {
        // ����Ȃ��ꍇ�Ɠ����ꍇ�𗼕�����
        res = max(rec(i + 1, j), rec(i + 1, j - w[i])) + v[i];
    }
    return res;
}

void solve() {
    print("%d\n", rec(0, W));
}

int main()
{
    cin >> n >> W;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];

}
