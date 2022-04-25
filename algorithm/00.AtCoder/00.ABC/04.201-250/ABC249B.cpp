#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    map<char,int> mp;
    int n = s.size();
    for (int i = 0; i < n; ++i) mp[s[i]]++;
    bool flag = true;
    for (auto x : mp) {
        if (x.second > 1) flag = false;
    }

    bool cap = false, small = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') small = true;
        if (s[i] >= 'A' && s[i] <= 'Z') cap = true;
    }

    flag &= (small & cap);

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
