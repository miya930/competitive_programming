#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> ans;
    
    if (n%2 == 0) {

        for (int i = 1; i <= n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (j == n-i+1) continue;
                ans.push_back(make_pair(i, j));
            }
        }
    } else {
        for (int i = 1; i < n; ++i) {
            ans.push_back(make_pair(i, n));
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (j == n-i) continue;
                ans.push_back(make_pair(i, j));
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i].first << " " << ans[i].second << endl;

    return 0;
}
