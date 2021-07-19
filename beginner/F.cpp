#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main(){
    string s, t;
    cin >> s >> t;

    vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1, 0));
    dp[0][0] = 0;

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if(s[i-1] == t[j-1]) chmax(dp[i][j], dp[i-1][j-1] + 1);
            else {
                chmax(dp[i][j], dp[i-1][j]);
                chmax(dp[i][j], dp[i][j-1]);
            }
        }
    }
    
    int len = dp[s.size()][t.size()];
    int i = s.size();
    int j = t.size();

    string ans = "";
    while(len>0) {
        if(s[i-1]==t[j-1]) {
            ans += s[i-1];
            i--;
            j--;
            len--;
        } else if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
