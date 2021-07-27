#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    ll ans = 0;

    while (n > 0) {
        int mii1 = 0, mii2 = 1;
        if (L[mii1] > L[mii2]) swap(mii1, mii2);

        for (int i = 2; i < n; ++i) {  // ������ւ�͍ŏ��l��������v���O����
            if (L[i] < L[mii1]) {      // 2�̐����̂����A�������ق�����i���������ꍇ
                mii2 = mii1;           
                mii1 = i;
            }
            else if (L[i] < L[mii2]) { // 2�̐����̂����A�傫���ق�����i���������ꍇ
                mii2 = i;
            }
        }

        // �����𕹍�
        int t = L[mii1] + L[mii2];
        ans += t;

        if (mii1 == n - 1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[n-1];
        n--;
    }
}
