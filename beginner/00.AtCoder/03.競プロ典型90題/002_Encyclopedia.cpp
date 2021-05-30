/**
 * 
 * ã£ÉvÉçìTå^90ñ‚
 * 002 - Encyclopedia of Parentheses
 * link : https://atcoder.jp/contests/typical90/tasks/typical90_b
 * 
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int bits = 0; bits < (1<<n); ++bits) {
        string ans = "";
        int cnt_l = 0;
        int cnt_r = 0;
        for (int i = n-1; i >= 0; --i) {
            if (bits & (1<<i)) {
                ans += ')';
                cnt_r++;
                if (cnt_l - cnt_r < 0) break;
            }
            else {
                ans += '(';
                cnt_l++;
            }
        }
        if (cnt_l == cnt_r) cout << ans << endl;
    }
}
