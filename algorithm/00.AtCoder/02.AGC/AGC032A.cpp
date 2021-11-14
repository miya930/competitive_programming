/**
   created: 22.10.2021 23:03:15
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = b.size()-1; j >= 0; --j) {
            if (b[j] == j+1) {
                b.erase(b.begin()+j);
                ans.push_back(j+1);
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << -1 << endl;
            return 0;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

    return 0;
}
