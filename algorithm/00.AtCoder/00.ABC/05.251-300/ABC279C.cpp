#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h), t(h);
    for (int i = 0; i < h; i++) cin >> s[i];
    for (int i = 0; i < h; i++) cin >> t[i];

    map<string, int> mps, mpt;

    for (int j = 0; j < w; j++) {
        string tmp1 = "";
        string tmp2 = "";
        for (int i = 0; i < h; i++) {
            tmp1.push_back(t[i][j]);
            tmp2.push_back(s[i][j]);
        }
        mpt[tmp1]++;
        mps[tmp2]++;
    }

    bool isok = true;
    for (auto x : mpt) {
        string t1 = x.first;
        int t2 = x.second;
        if (mps[t1] != t2) isok = false;
    }

    if (isok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
