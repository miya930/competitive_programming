#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    map<int,int> mp;
    mp[a]++; mp[b]++; mp[c]++; mp[d]++; mp[e]++;

    bool flg = true;
    if (mp.size() != 2) {
        cout << "No" << endl;
        return 0;
    }

    bool two = false, three = false;
    for (auto x : mp) {
          if (x.second == 2) two = true;
          else if (x.second == 3) three = true;
    }

    if (two & three) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
