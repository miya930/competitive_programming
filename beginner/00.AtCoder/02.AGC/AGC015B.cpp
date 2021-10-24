/**
   created: 23.10.2021 18:25:45
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    ll ans = 2*(n-1);
    for (int i = 1; i < n-1; ++i) {
        if (s[i] == 'U') ans += (2*i+(n-1-i));
        else ans += (i+2*(n-1-i));
    }
    cout << ans  << endl;

    return 0;
}
