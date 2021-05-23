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
        string s = "";
        bool flag = true;
        int cnt_r = 0;
        int cnt_l = 0;
        for (int i = n-1; i >= 0; --i) {
            if ((bits & (1<<i)) == 0) {
                s += '(';
                cnt_l++;
            } else {
                s += ')';
                cnt_r++;
            }
            if (cnt_r > cnt_l) {
                flag = false;
                break;
            }
        }
        if (flag == true && cnt_r == cnt_l) cout << s << endl;

    }

}
