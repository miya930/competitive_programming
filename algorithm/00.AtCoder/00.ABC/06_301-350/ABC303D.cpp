#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;

    vector<pair<int,ll>> vec;
    int cur = 0; ll cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            cnt++;
            if (s[i] == 'A') cur = 0;
            else cur = 1;

            continue;
        }

        if ((cur == 0 && s[i] == 'A') || (cur == 1 && s[i] == 'a')) cnt++;
        else if (cur == 0 && s[i] == 'a') {
            vec.push_back(make_pair(0, cnt));
            cnt = 1;
            cur = 1;
        } else if (cur == 1 && s[i] == 'A') {
            vec.push_back(make_pair(1, cnt));
            cnt = 1;
            cur = 0;
        }
    }
    //if (s[s.size()-1] == s[s.size()-2]) cnt--;
    vec.push_back(make_pair(cur, cnt));

    vector<vector<ll>> dp(s.size()+1, vector<ll>(2, infl));
    dp[0][0] = 0;
    for (int i = 0; i < vec.size(); i++) {
        int cur = vec[i].first;
        ll cnt = vec[i].second;

        if (cur == 0) { // 'A'
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + y * cnt);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + y * cnt + z);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + x * cnt + z);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + x * cnt);
        } else {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + x * cnt);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + x * cnt + z);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + y * cnt + z);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + y * cnt);
        }
        
    }
    ll ans = infl;
    ans = min(ans, dp[vec.size()][0]);
    ans = min(ans, dp[vec.size()][1]);
    cout << ans << endl;
}
