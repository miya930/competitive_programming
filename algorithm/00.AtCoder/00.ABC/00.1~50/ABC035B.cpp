#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    int t;
    cin >> s >> t;

    map<char, pair<int,int>> mp;
    mp['L'] = {-1, 0};
    mp['R'] = {1, 0};
    mp['U'] = {0, 1};
    mp['D'] = {0, -1};

    int n = s.size();
    int qcnt = 0;
    pair<int,int> now = {0, 0};
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            now.first += mp[s[i]].first;
            now.second += mp[s[i]].second;
        } else {
            qcnt++;
        }
    }

    int x = now.first, y = now.second;
    int ma = abs(now.first) + abs(now.second);
    int mi = ma, dist = ma;
    
    if (dist <= qcnt) {
        if (dist%2 == qcnt%2) mi = 0;
        else mi = 1;
    } else {
        mi = dist - qcnt;
    }

    ma = dist + qcnt;

    if (t == 1) cout << ma << endl;
    else cout << mi << endl;

    return 0;
}
