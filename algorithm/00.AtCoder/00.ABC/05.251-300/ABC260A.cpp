#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    mp[s[0]]++;
    mp[s[1]]++;
    mp[s[2]]++;

    if (mp[s[0]] == 1) cout << s[0] << endl;
    else if (mp[s[1]] == 1) cout << s[1] << endl;
    else if (mp[s[2]] == 1) cout << s[2] << endl;
    else cout << -1 << endl;

    return 0;
}
