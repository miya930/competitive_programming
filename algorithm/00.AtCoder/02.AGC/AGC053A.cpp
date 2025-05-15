#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n+1);
    for (int i = 0; i < n+1; i++) cin >> a[i];

    int d = 1001001001;
    for (int i = 0; i < n; i++) {
        d = min(d, abs(a[i]-a[i+1]));
    }

    vector<vector<int>> ans;
    for (int k = 1; k <= d; k++) {
        vector<int> v;
        for (int j = 0; j < n+1; j++) {
            v.push_back((a[j]+k-1)/d);
        }
        ans.push_back(v);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < n+1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
