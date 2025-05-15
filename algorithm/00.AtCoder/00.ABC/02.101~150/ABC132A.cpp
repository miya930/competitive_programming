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
    mp[s[3]]++;

    if (mp.size() == 2){
        bool ok = true;
        for (auto x : mp) {
            if (x.second != 2) ok = false;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    cout << "No" << endl;

    return 0;
}
