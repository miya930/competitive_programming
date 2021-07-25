#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int mod = 998244353;
typedef pair<char, int> P;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, pair<char, int> > mp;

    for (int i = 1; i <= k; ++i) {
        char c; int k;
        cin >> c >> k;
        mp[i] = P(c, k);
    }

    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        long long cnt = 0;
        bool flag = true;
        for (int j = 0; j < mp.size(); ++j) {
            if (mp[j].second == i) flag = false;
            else if (mp[j].first == 'L' && mp[j].second < i) {
                cnt++;
            }
            else if (mp[j].first == 'R' && mp[j].second > i) cnt++;
        }
        if (cnt > 0 && flag) ans *= cnt;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
