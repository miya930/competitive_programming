#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    ll ans = 0;

    int n = s.size();

    int a = 0, bc = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a++;
        else if (s[i] == 'B' && s[i+1] == 'C') {
            ans += a;
            i++;
        } else a = 0;
    }

    cout << ans << endl;

    return 0;

}
