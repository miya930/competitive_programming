// �o�P�b�g�E�\�[�g�𗘗p����B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    // �o�P�b�g
    vector<int> Num(N,0);

    for (int i = 0; i < N; i++) {
        Num[A[i]-1]++;
    }

    // ����ނ̃{�[�������邩
    int cnt = 0;
    // ��
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (Num[i])
            cnt++;
    }

    // �~���Ƀ\�[�g
    sort(Num.rbegin(), Num.rend());


    // Num�̗v�f0����K�Ԗڈȍ~�̘a�����߂��������ƂȂ�
    for (int i = K; i < N; i++) {
        ans += Num[i];
    }

    cout << ans << endl;


}
