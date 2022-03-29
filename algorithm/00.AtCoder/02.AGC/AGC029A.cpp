#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    
    int n = s.size();
    int cur = 0;
    ll ans = 0;
    bool b = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') b = true;
        if (b == false && s[i] == 'W') cur++;
        if (b == true && s[i] == 'W') {
            ans += (i-cur);
            cur++;
        }
    }

    cout << ans << endl;
    return 0;
}
