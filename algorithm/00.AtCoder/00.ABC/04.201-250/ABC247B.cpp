#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];

    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i]]++;
        mp[t[i]]++;
    }

    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (s[i] == t[i]) {
            if (mp[s[i]]-1 > 1) flag = false;
        } else if (mp[s[i]] > 1 && mp[t[i]] > 1) {
            flag = false;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
