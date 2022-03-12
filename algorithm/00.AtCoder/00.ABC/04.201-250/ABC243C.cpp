#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> pa(n);
    for (int i = 0; i < n; ++i) cin >> pa[i].first >> pa[i].second;

    string s;
    cin >> s;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[pa[i].second].push_back(i);
    }

    bool flag = false;
    for (auto x : mp) {
        pair<int,int> rpa(0, inf), lpa(0, 0);
        for (auto y : x.second) {
            if (s[y] == 'R') {
                int xx = pa[y].first;
                rpa.first = 1;
                rpa.second = min(rpa.second, xx);
            } else{
                int xx = pa[y].first;
                lpa.first = 1;
                lpa.second = max(lpa.second, xx);
            } 
        }
        if (rpa.first == 1 && lpa.first == 1 && rpa.second <= lpa.second) flag = true;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
