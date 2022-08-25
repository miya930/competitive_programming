#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    string str = "atcoder";

    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = 0; j < (int)s.size(); ++j) {
            int cnt;
            if (s[j] == str[i]) cnt = j;
            else continue;

            for (int k = j-1; k >= i; k--) {
                swap(s[k], s[k+1]);
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
