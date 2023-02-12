#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int t;
            cin >> t;
            a[i].push_back(t);
        }
    } 

    int ans = 0;
    for (int bit = 0; bit < 1 << m; bit++) {
        vector<int> vec;
        set<int> sts;
        for (int i = 0; i < m; i++) {
            if (bit>>i&1) {
                for (int j = 0; j < a[i].size(); j++) {
                    sts.insert(a[i][j]);
                }
            }
        }
        if (n == sts.size()) ans++;
    }

    cout << ans << endl;

    return 0;
}
