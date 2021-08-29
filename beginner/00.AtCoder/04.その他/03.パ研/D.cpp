/*
 * パ研杯2019 パ研軍旗
 * https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<string> s(5);
    for (int i = 0; i < 5; ++i) cin >> s[i];

    vector<vector<int> > columns(n, vector<int>(3, 0)), rows(5, vector<int>(3, 0)); // R：0, B：1, W：2

    for (int j = 0; j < n; ++j) {
        map<char, int> mp;
        for (int i = 0; i < 5; ++i) mp[s[i][j]]++;
        
        vector<int> cnt(3, 5);

        for (auto x : mp) {
            if (x.first == 'R') cnt[0] -= x.second;
            else if (x.first == 'B') cnt[1] -= x.second;
            else if (x.first == 'W') cnt[2] -= x.second;
        }

        for (int i = 0; i < 3; ++i) columns[j][i] = cnt[i];
    }

    vector<vector<int> > dpc(n, vector<int>(3, INF));

    for (int i = 0; i < 3; ++i) dpc[0][i] = columns[0][i];

    for (int i = 1; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                dpc[i][k] = min(dpc[i][k], (dpc[i-1][j] + columns[i][k]));
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 3; ++i) {
        ans = min(ans, dpc[n-1][i]);
    }

    cout << ans << endl;
}
