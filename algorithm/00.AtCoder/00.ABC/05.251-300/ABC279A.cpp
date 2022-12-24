#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    map<int,int> mp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v') mp[1]++;
        else mp[2]++;
    }

    cout << mp[1] + 2*mp[2] << endl;

    return 0;
}
