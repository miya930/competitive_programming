#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int maximum_same(vector<int> R) {
    map<int,int> mp; int ret = 0;
    for (int i = 0; i < R.size(); ++i) {
        mp[R[i]]++;
        ret =  max(ret, mp[R[i]]);
    }
    return ret;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int> > p(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> p[i][j];
        }
    }

    int ans = 0;
    for (int bits = 1; bits < (1<<h); ++bits) {
        vector<int> R;
        for (int i = 0; i < w; ++i) {
            int idx = -1; bool flag = false;
            for (int k = 0; k < h; ++k) {
                if ((bits & (1<<k)) == 0) continue;
                if (idx == -1) idx = p[k][i];
                else if (idx != p[k][i]) flag = true;
            }
            if (flag != true) R.push_back(idx);
        }

        int cnth = 0; int cntw = maximum_same(R);
        for (int i = 0; i < h; ++i) {
            if ((bits & (1<<i)) != 0) cnth++;
        }
        ans = max(ans, cnth*cntw);
    }
    cout << ans << endl;
    return 0;
}


/* 2022.4.11 復習 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> vec(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) cin >> vec[i][j];
    }

    int ans = 0;
    for (int bits = 1; bits < 1<<h; ++bits) {
        vector<vector<int>> tmp;
        for (int i = 0; i < h; ++i) {
            if (bits>>i & 1) {
                tmp.push_back(vec[i]);
            }
        }
        
        int cnt = 0;
        map<int,int> mp;
        for (int j = 0; j < w; ++j) {
            int flag = true;
            for (int i = 0; i < (int)tmp.size()-1; ++i) {
                if (tmp[i][j] != tmp[i+1][j]) flag = false;
            }
            if (flag) mp[tmp[0][j]] += tmp.size();

        }

        for (auto x : mp) {
            cnt = max(cnt, x.second);
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}

