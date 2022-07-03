#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < (int)s.size(); ++i) mp[s[i]]++;
    bool a = false, b = false;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == 'A') a = true;
        else if (s[i] == 'B') b = true;
    }

    if (a && b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
