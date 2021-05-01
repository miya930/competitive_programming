#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a)
{
    //�x�[�X�P�[�X
    if (i == 0) {
        if (w == 0)
            return true;
        else
            return false;
    } 

    // a[i-1]��I�΂Ȃ��ꍇ
    if (func(i-1, w, a)) return true;

    // a[i-1]��I�ԏꍇ
    if (func(i-1, w - a[i-1], a)) return true;

    // �ǂ����false�̏ꍇ�Afalse��Ԃ��B
    return false;
}

int main(void)
{
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    if(func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
