#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
   string s;
   cin >> s;

   map<char, int> mp;
   for (int i = 0; i < 3; ++i) mp[s[i]]++;

   int n = mp.size();

   int ans = 0;
   if (n == 1) ans = 1;
   else if (n == 2) ans = 3;
   else ans = 6;

    cout << ans << endl;

    return 0;
}
