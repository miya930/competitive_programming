#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    string ans = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ans += '0';
        else if (s[i] == '1') ans += '1';
        else {
            if (ans.size() == 0) continue;
            ans.erase(ans.end()-1);
        }
    }

    cout << ans << endl;
    return 0;
}
