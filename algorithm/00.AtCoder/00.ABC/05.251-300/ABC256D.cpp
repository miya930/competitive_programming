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

    sort(pa.begin(), pa.end());

    vector<pair<int,int>> ans;

    int start = pa[0].first;
    int cur_end = pa[0].second;
    for (int i = 1; i < n; ++i) {
        if (cur_end < pa[i].first) {
            ans.push_back(make_pair(start, cur_end));
            start = pa[i].first;
            cur_end = pa[i].second;
        } else {
            if (cur_end < pa[i].second) cur_end = pa[i].second;
        }
    }

    ans.push_back(make_pair(start, cur_end));

    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl; 
    }

    return 0;
}
