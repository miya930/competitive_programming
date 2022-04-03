#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<vector<int>> calcNext(const string &s) {
    int n = (int)s.size();
    vector<vector<int>> res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][s[i]-'a'] = i;
    }
    return res;
}

int main()
{
    string s, t;
    cin >> s >> t;

    vector<vector<int>> vec = calcNext(s);

    bool flag = false;
    for (int i = 0; i < t.size(); ++i) {
        int nxt = vec[0][t[i]-'a'];
        if (nxt == (int)s.size()) {
            flag = true;
        }
    }

    if (flag) {
        cout << -1 << endl;
        return 0;
    }

    ll cur = 0, cnt = 0;
    int si = t.size();
    for (int i = 0; i < si; ++i) {
        int nxt = vec[cur][t[i]-'a'];
        if (nxt == s.size()) {
            cnt++;
            cur = 0;
            nxt = vec[cur][t[i]-'a'];
        }
            
        cur = nxt+1;
    }

    cout << cnt*(ll)s.size() + cur << endl;
    return 0;
}
