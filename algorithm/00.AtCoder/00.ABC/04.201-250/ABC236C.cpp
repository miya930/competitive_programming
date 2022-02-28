#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> t[i];

    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        mp[t[i]] = 2;
    }
    
    for (int i = 0; i < n; ++i) {
        if (mp[s[i]] != 2) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
