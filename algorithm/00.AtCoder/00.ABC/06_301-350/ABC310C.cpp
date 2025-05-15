#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    map<string, int> mp;
    
    for (int i = 0; i < n; i++) {
        string rev = s[i];
        reverse(rev.begin(), rev.end());
        if (mp.count(s[i])) mp[s[i]]++;
        else if (mp.count(rev)) mp[rev]++;
        else mp[s[i]]++;
    }

    cout << mp.size() << endl;

    return 0;
}
