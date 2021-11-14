#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0 ;i < n; ++i) cin >> s[i];

    vector<vector<int>> vec(n, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            int tmp = s[i][j] - 'a';
            vec[i][tmp]++;
        }
    }

    string ans = "";
    vector<bool> none(26, false);
    vector<int> num(26, inf);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (vec[i][j] == 0) none[j] = true;
            if (!none[j]) num[j] = min(num[j], vec[i][j]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (!none[i]) {
            for (int j = 0; j < num[i]; ++j) {
                ans += (char)(i+'a');
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
