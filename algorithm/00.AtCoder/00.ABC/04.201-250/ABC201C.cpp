#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    int bit_o = 0;
    int bit_x = 0;

    for (int i = 0; i < 10; ++i){
        if (s[i] == 'o') {
            cnt++;
            bit_o |= (1<<i);
        } else if (s[i] == 'x')
            bit_x |= (1<<i);
    }

    if (cnt > 4) {
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    for (int i = 0; i < 10; ++i) {
        int bit_check = 0;
        bit_check |= (1<<i);
        for (int j = 0; j < 10; ++j) {
            int bit_check2 = bit_check;
            bit_check2 |= (1<<j);
            for (int k = 0; k < 10; ++k) {
                int bit_check3 = bit_check2;
                bit_check3 |= (1<<k);
                for (int l = 0; l < 10; ++l) {
                    int bit_check4 = bit_check3;
                    bit_check4 |= (1<<l);
                    if ((bit_o & bit_check4) != bit_o || (bit_x & bit_check4) != 0) {
                        continue;
                    }
                    res++;
                }
            }
        }
    }
    cout << res << endl;
}
