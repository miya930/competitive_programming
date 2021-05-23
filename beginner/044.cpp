/**
 * ã£ÉvÉçìTå^ 90ñ‚
 * 044 - Shift and Swapping
 * URLÅFhttps://atcoder.jp/contests/typical90/tasks/typical90_ar
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

        } else if (t == 2) {
            shift = (shift + n - 1) % n;
        }
    }

}

