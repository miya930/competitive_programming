#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n+1);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<vector<int>> vec(11, vector<int>(n));
    int ans = inf;
    for (int cnt = 0; cnt < 10; ++cnt) {
        map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                int tmp = s[i][j] - '0';
                if (tmp == cnt) mp[j]++;
            }
        }
        int ma = 0;
        for (auto x : mp) {
            ma = max(ma, x.second);
        }
        int ma2 = 0;
        for (auto x : mp) {
            if (x.second == ma) {
                ma2 = max(ma2, x.first);
            }
        }
        ans = min(ans, (ma-1)*10+ma2);
    }

    cout << ans << endl;
    return 0;
}
