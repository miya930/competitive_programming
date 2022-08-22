#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    vector<pair<int,int>> pas, pat;
    int cnt = 1;

    if (s.size() > t.size()) {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 0; i < s.size()-1; ++i) {
        if (s[i] != s[i+1]) {
            pas.push_back(make_pair((int)(s[i]-'a'), cnt));
            cnt = 1;
        } else {
            cnt++;
        }
    }
    pas.push_back(make_pair((int)(s[s.size()-1]-'a'), cnt));
    cnt = 1;

    for (int i = 0; i < t.size()-1; ++i) {
        if (t[i] != t[i+1]) {
            pat.push_back(make_pair((int)(t[i]-'a'), cnt));
            cnt = 1;
        } else {
            cnt++;
        }
    }

    pat.push_back(make_pair((int)(t[t.size()-1]-'a'), cnt));

    bool yes = true;
    if (pas.size() != pat.size()) {
        cout << "No" << endl;
        return 0;
    } else {
        for (int i = 0; i < (int)pas.size(); ++i) {
            if (pas[i].first != pat[i].first) yes = false;
            if ((pas[i].second != pat[i].second) && ((pas[i].second == 1)|| (pas[i].second > pat[i].second))) yes = false;
        }
    }

    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
