/**
 * 
 * ���v���T�^90��
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


/*************** 2022.3.13 復習 *****************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    for (int bits = 0; bits < (1<<n)-1; bits++) {
        string s = "";
        for (int i = n-1; i >= 0; --i) {
            if ((bits>>i) & 1) s += ')';
            else s += '(';
        }
        
        int cnt = 0;
        bool flag = true;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] == '(') cnt++;
            else cnt--;

            if (cnt < 0) flag = false;
        }
        
        if (flag && cnt == 0) cout << s << endl;
    }

    return 0;
}
