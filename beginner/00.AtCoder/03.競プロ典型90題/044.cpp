/**
 * 競プロ典型 90問
 * 044 - Shift and Swapping
 * URL：https://atcoder.jp/contests/typical90/tasks/typical90_ar
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int shift = 0;
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            --x, --y;
            swap(a[(x + shift) % n], a[(y + shift) % n]);
        } 
        if (t == 2) {
            shift = (shift + n - 1) % n; // 右方向にシフトするのでshiftは左方向にシフトする.
        }
        if (t == 3) {
            --x;
            cout << a[(x+shift) % n] << endl;
        }
    }
    return 0;

}

