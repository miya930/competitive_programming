#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < (int)s[i].size(); ++j) {
            if ((s[i][j-1] == 'A') && (s[i][j] == 'B')) ans++;
        }
    }

    vector<int> cnt(3,0);
    for (int i = 0; i < n; ++i) {
        if ((s[i][0] =='B') && (s[i][s[i].size()-1] == 'A')) cnt[0]++;
        else if (s[i][0] == 'B') cnt[1]++;
        else if (s[i][s[i].size()-1] == 'A') cnt[2]++;  
    }

    if (cnt[0] == 0) ans += min(cnt[1], cnt[2]);
    else if ((cnt[1] + cnt[2]) > 0) ans  += cnt[0] + min(cnt[1], cnt[2]);
    else if ((cnt[1] + cnt[2]) == 0) ans += cnt[0] - 1;


    cout << ans << endl;
}
