/**
   created: 10.10.2021 11:50:43
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

char base[] = {'A', 'C', 'G', 'T', '-'};
int dp[1000][1000];

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    string s, t;
    cin >> s >> t;

    int base_num = sizeof(base) / sizeof(base[0]);
    vector<vector<int> > score_table(base_num, vector<int>(base_num));
    map<char, int> conv;
    
    for (int i = 0; i < base_num; ++i) conv[base[i]] = i;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            dp[i][j] = -inf;
        }
    }

    for (int i = 0; i < base_num; ++i) {
        for (int j = 0; j < base_num; ++j) {
            if (i == j && i != 4 && j != 4) score_table[i][j] = 1;
            else if (i == 4 || j == 4) score_table[i][j] = -5;
            else score_table[i][j] = -3;
        }
    }

    dp[0][0] = 0;
    vector<vector<pair<int, int> > > memo(1000, vector<pair<int, int> > (1000, make_pair(-1, -1))); 

    for (int i = 0; i <= s.size()+1; ++i) {
        for (int j = 0; j <= t.size()+1; ++j) {
            if (i < (int)s.size() && j < (int)t.size()) {
                if (chmax(dp[i+1][j+1], dp[i][j]+score_table[conv[s[i]]][conv[t[j]]])) {
                    memo[i+1][j+1] = make_pair(i, j);
                }
            } 
            if (i < (int)s.size()) {
                if (chmax(dp[i+1][j], dp[i][j]+score_table[conv[s[i]]][conv['-']])) {
                    memo[i+1][j] = make_pair(i, j);
                }
            } 
            if (j < (int)t.size()) {
                if (chmax(dp[i][j+1], dp[i][j]+score_table[conv['-']][conv[t[j]]])) {
                    memo[i][j+1] = make_pair(i, j);
                }
            }
        }
    }

    // 復元
    int si = (int)s.size(), ti = (int)t.size();
    string sans = "", tans = "";
    while (si > 0 || ti > 0) {

        int temps = memo[si][ti].first;
        int tempt = memo[si][ti].second;

        if (temps == si) sans += "-";
        else sans += s[si-1];
        if (tempt == ti) tans += "-";
        else tans += t[ti-1];
        
        si = temps;
        ti = tempt;
    }

    reverse(sans.begin(), sans.end());
    reverse(tans.begin(), tans.end());

    cout << sans << endl;
    cout << tans << endl;
    
    return 0;
}
