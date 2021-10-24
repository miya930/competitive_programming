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

    string ans;
    if (s[n-1] == 'r' && s[n-2] == 'e') ans = "er";
    else ans  = "ist";

    cout << ans << endl;
    return 0;
}
