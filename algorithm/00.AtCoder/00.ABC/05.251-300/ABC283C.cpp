#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int cur = 0;
    int ans = 0;
    int si = s.size()-1;
    while(1) {
        if (cur == s.size()) break;

        if (s[cur] != '0') {
            cur++;
        }else {
            if (si - cur + 1 >= 2) {
                string str = s.substr(cur, 2);
                if (str == "00") {
                    cur+=2;
                } else {
                    cur++;
                }
            } else {
                cur++;
            }
        }

        ans++;
    }

    cout << ans << endl;

    return 0;
}
