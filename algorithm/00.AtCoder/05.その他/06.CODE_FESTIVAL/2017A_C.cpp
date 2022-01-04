#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    map<char, int> mp;
    vector<int> cnt(4);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) mp[s[i][j]]++;
    }

    for (auto x : mp) cnt[x.second%4]++;
    
    bool ok = true;
    if (h%2 == 0 && w%2 == 0) {
        if (cnt[1] + cnt[2] + cnt[3] > 0) ok = false;
    } else if (h%2 == 1 && w%2 == 1) {
        if (cnt[1]+cnt[3] > 1) ok = false;
        else if (cnt[2] > h/2 + w/2) ok = false;
    } else {
        if (cnt[1]+cnt[3] > 0) ok = false;
        else if (h%2 == 1 && cnt[2] > w/2) ok = false;
        else if (w%2 == 1 && cnt[2] > h/2) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}
