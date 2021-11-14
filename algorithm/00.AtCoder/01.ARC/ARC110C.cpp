#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        mp[p[i]] = i;
    }

    vector<int> ans;
    bool ng = false;
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) continue;
        int temp = mp[i];
        for (int j = temp; j > i; --j) {
            swap(p[j], p[j-1]);
            ans.push_back(j);
            mp[p[j]] = j;
            mp[p[j-1]] = j-1;
            if (p[j] != j && j != temp) {
                ng = true;
                break;
            }
        }
    }

    if (ans.size() != n-1) ng = true;

    if (ng) cout << -1 << endl;
    else {
        for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << endl;
    }

    return 0;
}
