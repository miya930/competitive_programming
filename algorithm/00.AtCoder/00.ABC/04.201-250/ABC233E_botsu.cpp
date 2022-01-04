#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string x;
    cin >> x;
    
    string ans = x;

    for (int i = 1; i < (int)x.size(); ++i) {
        string str = x.substr(0, i);

        cout << str << endl;
        
        for (int j = 0; j < (int)str.size(); ++j) {
            bool flag = true;
            string copy = ans, copystr = str;
            reverse(copy.begin(), copy.end());
            reverse(copystr.begin(), copystr.end());

            int dig = j;
            int carry = 0;

            while (flag) {
                int cn = copy[dig] - '0' + carry;
                int sn = 0;
                if (str.size() > dig) {
                    sn = copystr[dig]  - '0';
                } 
                
                cout << "cn = " << cn << "  sn = " << sn << endl;  

                if (cn+sn < 10) {
                    copy[dig] = (cn+sn)%10 + '0';
                    flag = false;
                } else {
                    copy[dig] = (cn+sn)%10 + '0';
                    carry = (cn+sn)/10;
                }

                cout << "copy = " << copy << endl;

                if (dig == copy.size()-1) {
                    if (carry == 1) {
                        copy.push_back('1');
                        flag = false;
                    }
                } else {
                    dig++;
                }
                if (!flag) break;
            }
            cout << copy << endl;
            reverse(copy.begin(), copy.end());
            ans = copy;
        }
        cout << ans << endl;
    }
    
    cout << ans << endl;

    return 0;
}
