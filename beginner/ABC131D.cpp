#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    //���j�Ftuple���g�p��A[i], B[i], B[i]-A[i]��v�f�Ƃ���z������
    // B[i]-A[i]�̒l�Ń\�[�g

    vector<tuple<int, int, int> > tup(N);

}
