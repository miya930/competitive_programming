#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<int, int>> func(string s) {
    vector<pair<int, int>> res;
    int n = s.size();

    char pre = s[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (pre != s[i]) {
            res.push_back({pre, cnt});
            pre = s[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }

    res.push_back({pre, cnt});
    return res;
}
