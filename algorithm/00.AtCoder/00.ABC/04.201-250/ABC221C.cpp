#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

ll toll(string s) {
    ll res = 0;
    ll dig = 1;
    for (int i = s.size()-1; i >= 0; --i) {
        res += dig*(s[i]-'0');
        dig *= 10;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    ll ans = 0;
    for (int bit = 0; bit < 1<<n; ++bit) {
        string scopy = "";
        string ss = "";
        ll temp = 0;
        for (int i = 0; i < n; ++i) {
            if (bit>>i&1) {
                scopy.push_back(s[i]);
            } else {
                ss.push_back(s[i]);
            }
        }
        sort(scopy.rbegin(), scopy.rend());
        sort(ss.rbegin(), ss.rend());

        temp = toll(scopy)*toll(ss);
        ans = max(ans, temp);
    }

    cout << ans << endl;
}
