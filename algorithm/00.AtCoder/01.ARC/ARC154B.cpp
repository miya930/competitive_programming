#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    string ss = s, tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    bool ng = false;
    for (int i = 0; i < n; i++) {
        if (ss[i] != tt[i]) {
            ng = true;
            break;
        }
    }
    if (ng) {
        cout << -1 << endl;
        return 0;
    }

    map<char, multiset<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]].insert(i);
    }

    int ans = 0;
    int cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        int j = i + cnt;
        if (j < 0) break;
        if (s[j] == t[i]) continue;

        char c = t[i];
        int idx = *mp[c].begin();
        mp[c].erase(mp[c].begin());

        ans = max(ans, idx+1);

        cnt++;
    }
    
    cout << ans << endl;

    return 0;
}
