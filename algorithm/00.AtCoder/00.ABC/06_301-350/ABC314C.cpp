#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    map<int, vector<pair<int,char>>> mp;
    for (int i = 0; i < n; i++) {
        mp[c[i]].push_back(make_pair(i, s[i]));
    }

    for (auto t : mp) {
        int sz = t.second.size();
        char las = t.second[sz-1].second;
        for (int i = sz-1; i > 0; i--) {
            int cur = t.second[i].first;
            int nxt = t.second[i-1].first;
            s[cur] = s[nxt];
        }
        int idx = t.second[0].first;
        s[idx] = las;
    }

    cout << s << endl;
    return 0;
}
