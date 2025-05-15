#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    int x;
    cin >> x;

    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == x) {
                ans.push_back(make_pair(a[i].size(), i+1));
                break;
            }
        } 
    }
    
    sort(ans.begin(), ans.end());
    if (ans.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = ans[0].first;

    vector<int> ret;
    for (int i = 0; i < ans.size(); i++) {
        if (cnt == ans[i].first) {
            ret.push_back(ans[i].second);
        } else {
            break;
        }
    }
    sort(ret.begin(), ret.end());


    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;

    return 0;
}
