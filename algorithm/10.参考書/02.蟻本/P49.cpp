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

        for (int i = 2; i < n; ++i) {  // ここらへんは最小値を見つけるプログラム
            if (L[i] < L[mii1]) {      // 2つの整数のうち、小さいほうよりもiが小さい場合
                mii2 = mii1;           
                mii1 = i;
            }
            else if (L[i] < L[mii2]) { // 2つの整数のうち、大きいほうよりもiが小さい場合
                mii2 = i;
            }
        }

        // それらを併合
        int t = L[mii1] + L[mii2];
        ans += t;

        if (mii1 == n - 1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[n-1];
        n--;
    }
}
