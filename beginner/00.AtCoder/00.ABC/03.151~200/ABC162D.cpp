/**
   created: 23.10.2021 09:55:28
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    map<char, int> mp;
    mp['R'] = 0; mp['G'] = 1; mp['B'] = 2;

    vector<vector<int> > vec(n, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'R') vec[i][0]++;
        else if (s[i] == 'G') vec[i][1]++;
        else vec[i][2]++;
    }

    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < 3; ++j) {
            vec[i-1][j] += vec[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        if (s[i] == 'R') temp = 0;
        else if (s[i] == 'G') temp = 1;
        else temp = 2;
        for (int j = i+1; j < n; ++j) {
            if (j == n-1) continue;
            int temp2;
            if (s[j] == 'R') temp2 = 0;
            else if (s[j] == 'G') temp2 = 1;
            else temp2 = 2;

            if (temp == temp2) continue;

            int temp3 = (6-temp-temp2)%3;
            ans += vec[j][temp3];

            if (j+(j-i) < n) {
                if (mp[s[2*j-i]] == temp3) {
                    ans--;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
