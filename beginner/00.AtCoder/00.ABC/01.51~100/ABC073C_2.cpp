#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, ptr = 0, ans = 0;
    int A[100000];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);
    while(ptr<N) {
        int cc = A[ptr], cnt= 0;
        while (ptr < N && A[ptr] == cc)cnt++,ptr++;   // �����������o�����A�J�E���g�A�b�v���Ĕz������Ă���
        ans += cnt%2;                                 // ptr�����ڂ��Ă���z��v�f��Index
    }

    cout << ans << endl;
}
