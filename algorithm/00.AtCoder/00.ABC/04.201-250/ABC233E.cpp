#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string x;
    cin >> x;

    int s = 0, c = 0;
    for (auto &nx : x) {
        s += (nx-'0');
    }

    string res;
    for (int i = (int)x.size()-1;; --i) {
        c += s;
        res.push_back((c%10)+'0');
        c /= 10;
        if (i >= 0) {s -= (x[i]-'0');}
        if (i <= 0 && c == 0) {break;}
    } 
    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
