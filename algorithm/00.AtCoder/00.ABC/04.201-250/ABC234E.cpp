#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    string x;
    cin >> x;

    if (x.size() == 1 || x.size() == 2) {
        cout << x << endl;
        return 0;
    }

    int keta = x.size();
    string copy = x;
    while (1) {
        bool ok = false;
        ll ans = infl;
        for (int diff = -9; diff <= 9; ++diff) {
            int sento = copy[0] - '0';

            int prev = sento;
            bool flag = true;
            string tmp = "";
            tmp.push_back(copy[0]);
            for (int i = 0; i < keta-1; ++i) {
                prev += diff;
                if (prev < 0 || prev >= 10) {
                    flag = false;
                    break;
                }
                tmp.push_back(prev+'0');
            }
            
            if (flag) {
                ll tmp1 = stoll(x);
                ll tmp2 = stoll(tmp);
                if (tmp1 <= tmp2) {
                    if (ans > tmp2) {
                        ans = tmp2;
                        x = tmp;
                    }
                    ok = true;
                    break;
                }
            }
        }
        if (ok) break;
        else {
            if (copy[0] == '9') {
                copy[0] = '1';
                keta++;
            } else {
                copy[0]++;
            }
        }
    }

    cout << x << endl;
    return 0;
}
